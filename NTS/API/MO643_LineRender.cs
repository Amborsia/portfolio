using System;
using System.Collections;
using System.Collections.Generic;
using JSchool.Common.Script.BaseFramework.Lecture.Addressable.Sound;
using UnityEngine;

namespace JSchool.Contents.Math.MO643.Scripts
{
    public class MO643_LineRender : MonoBehaviour
    {
        void connectLine(Vector3 mousePos)
        {
            if (PrevPos != null && Mathf.Abs(Vector3.Distance(PrevPos, mousePos)) >= 0.001f && curLine != null)
            {
                PrevPos = mousePos;
                positionCount++;
                count++;
                curLine.positionCount = positionCount;
                curLine.SetPosition(positionCount - 1, mousePos);
            }
            MO643_Stage obj = FindObjectOfType<MO643_Stage>();
            obj.DelayGuide(false);

        }

        // 필기 인식하여 이어지는 선을 계산해서 자연스럽게 붙이는 작업

    }
