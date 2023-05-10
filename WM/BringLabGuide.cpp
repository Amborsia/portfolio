void BringLabGuide::startTouchDelayAction()
{
    CCDelayTime* delay_time = CCDelayTime::actionWithDuration(NEW_SHOP_GUIDE_TOUCH_DELAY_TIME);
    if (delay_time == nullptr) return;

    CCCallFunc* call_func = CCCallFunc::actionWithTarget(this, callfunc_selector(BringLabGuide::setIsReady));
    if (call_func == nullptr) return;

    CCFiniteTimeAction* seq = CCSequence::actionOneTwo(delay_time, call_func);
    if (seq == nullptr) return;

    this->runAction(seq);
}
// 브링연구소 팝업 연속클릭 방지법
// NEW_SHOP_GUIDE_TOUCH_DELAY_TIME를 0.1초로 설정하여 클릭 요청을 서버로 딜레이 이후 보낼 수 있도록 적용