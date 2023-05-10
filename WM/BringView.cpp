void BringView::openBringDetailView(BringObject* bringInfo, BRING_LAB_TAB_TYPE type) {


    BringSystem* bringSystem = GameManager::sharedManager()->getBringSystem();

    bringSystem->setIsBringLvUp(false);
    bringSystem->setMissionBringID(0);

    if (rootLT->getChildByTag(TFVUO_DETAIL_TAB_VIEW)) {
        rootLT->removeChildByTag(TFVUO_DETAIL_TAB_VIEW, true);
    }

    UIManager::shareInstance()->setSelectedBringType(type);

    BringLabTabListView* bringTabView = BringLabTabListView::node(bringInfo);

    bringTabView->setPosition(ccp(sprScaleBackground->getContentSize().width / 2 - UINode::getRealWinsize().width / 2, -sprScaleBackground->getContentSize().height / 2 - UINode::getRealWinsize().height / 2 + 21));
    bringTabView->setAnchorPoint(ccp(0.5f, 0.5f));
    rootLT->addChild(bringTabView, TFVUO_DETAIL_TAB_VIEW, TFVUO_DETAIL_TAB_VIEW);
}

// 브링연구소의 데이터를 매니저에서 불러와서 유저들에게 ui로 뿌려주는 장면


void BringView::updateMissionCompleteLabel() {
    if (rootLT->getChildByTag(TFVUO_DETAIL_TAB_VIEW))
    {
        BringLabTabListView* view = (BringLabTabListView*)rootLT->getChildByTag(TFVUO_DETAIL_TAB_VIEW);

        view->updateMissionCompleteLabel();
    }
}
// 브링연구소의 완료라벨 붙이기