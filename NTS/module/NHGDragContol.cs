using System.Collections;
using System.Collections.Generic;
using JSchool.Modules.Common.NHG.Common;
using UnityEngine;
using UnityEngine.EventSystems;

namespace JSchool.Modules.Common.NHG.Common
{
    public abstract class NHGDragContol : MonoBehaviour
    {
        protected NHGDragableObject[] draggableObjects;
        protected virtual void Awake()
        {
            draggableObjects = GetComponentsInChildren<NHGDragableObject>(true);
            foreach (var draggableObject in draggableObjects)
            {
                draggableObject.BeginDragPredicate += CanBeginDrag;
                draggableObject.DragPredicate += CanDrag;
                draggableObject.OnBeginDrag += BeginDrag;
                draggableObject.OnDrag += Drag;
                draggableObject.OnEndDrag += EndDrag;
            }
        }

        protected abstract bool CanBeginDrag(PointerEventData data);

        protected abstract bool CanDrag(PointerEventData data);
        
        protected abstract void BeginDrag(PointerEventData data);

        protected abstract void Drag(PointerEventData data);

        protected abstract void EndDrag(PointerEventData data);
    }
}


