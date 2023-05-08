using System;
using System.Collections;
using System.Collections.Generic;
using System.Threading;
using Cysharp.Threading.Tasks;
using DG.Tweening;
using JSchool.Common.Extensions;
using JSchool.Common.Script.BaseFramework.Lecture.Addressable.Sound;
using JSchool.Common.Script.BaseFramework.Lecture.Stage;
using JSchool.Common.Script.BaseFramework.Touch;
using JSchool.Common.Script.Manager.API;
using JSchool.Common.Utils;
using UniRx;
using XDPaint.Controllers;
using XDPaint.Core;
using UnityEngine;
using UnityEngine.UI;
using XDPaint;

namespace JSchool.Contents.Math.MO643.Scripts
{
    public class MO643_Stage : StageBase {

        private void SetUpClickObject(MO643_ClickButton item)
        {
            item.gameObject.ExGetOrAddComponent<ClickableObject>();
            item.ClickPredicate += (i1, i2) => Interact.CanInteractAndNotInteracting;
            item.OnClick += (i1, i2) =>
            {
                Interact.ClickInteraction();
                ClickButton(item.currentNum);
            };
        }

        protected override UniTask OnNoReactionGuideStart(CancellationToken token)
        {
            if (isKeypad)
            {
                foreach (var pad in padNumbers)
                {
                    pad.transform.DOScale(1.2f, 0.5f).SetLoops(2, LoopType.Yoyo);
                }
                foreach (var pad in padScale)
                {
                    pad.transform.DOScale(1.2f, 0.5f).SetLoops(2, LoopType.Yoyo);
                }
            }

            return base.OnNoReactionGuideStart(token);
        }

        // 기본 클릭 코드들 및 DOTWEEN 및 UniTask 사용 예시
    }

    
}