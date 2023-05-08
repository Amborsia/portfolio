using System;
using System.Linq;
using JSchool.Common.Extensions;
using JSchool.Common.Utils;
using UniRx;
using UniRx.Triggers;
using UnityEngine;
using UnityEngine.EventSystems;

namespace JSchool.Modules.Common.NHG.Common
{
    [DisallowMultipleComponent]
    [RequireComponent(typeof(BoxCollider2D))]
    public class NHGDragableObject : MonoBehaviour
    {
        protected virtual bool CanBeginDrag(PointerEventData data)
        {
            if (IsDragging())
                return false;

            if (BeginDragPredicate != null)
            {
                return BeginDragPredicate.GetInvocationList().All(func => ((Predicate<PointerEventData>)func).Invoke(data));
            }

            return true;
        }
        protected virtual bool CanDrag(PointerEventData data)
        {
            if (DragPredicate != null)
            {
                return DragPredicate.GetInvocationList().All(func => ((Predicate<PointerEventData>)func).Invoke(data));
            }

            return true;
        }

        private void AddObserver()
        {
            observer?.Dispose();

            var trigger = ObservableTriggerUtils.SetUpTrigger<ObservableBeginDragTrigger>(gameObject);

            observer = trigger
                .OnBeginDragAsObservable()
                .Where(CanBeginDrag)
                .Select(data =>
                {
                    BeginDrag(data);
                    OnBeginDrag?.Invoke(data);
                    return data;
                })
                .SelectMany(ObservableTriggerUtils.SetUpTrigger<ObservableDragTrigger>(gameObject)
                    .OnDragAsObservable()
                    .Where(IsSameBeginDragPointerEventData))
                .TakeUntil(ObservableTriggerUtils.SetUpTrigger<ObservableEndDragTrigger>(gameObject)
                    .OnEndDragAsObservable()
                    .Where(IsSameBeginDragPointerEventData)
                    .Select(data =>
                    {
                        EndDrag(data);
                        OnEndDrag?.Invoke(data);
                        return data;
                    }))
                .Where(CanDrag)
                .RepeatUntilDisable(gameObject)
                .Subscribe(data =>
                {
                    Drag(data);
                    OnDrag?.Invoke(data);
                });
        }

        // observer를 이용한 드래그 컨트롤 체크 작업
        // 드래그 작업에선 boxcollider는 필수기 때문에 무조건 붙어있는 것으로 작업함
    }
}


