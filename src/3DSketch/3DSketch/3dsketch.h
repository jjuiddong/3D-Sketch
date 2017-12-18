//
// 2017-12-12, jjuiddong
//
//
#pragma once


class c3DView;
class cCmdView;

class cViewer : public framework::cGameMain2
{
public:
	cViewer();
	virtual ~cViewer();

	virtual bool OnInit() override;
	virtual void OnUpdate(const float deltaSeconds) override;
	virtual void OnRender(const float deltaSeconds) override;
	virtual void OnEventProc(const sf::Event &evt) override;


public:
	c3DView *m_3dView;
	cCmdView *m_cmdView;
};
