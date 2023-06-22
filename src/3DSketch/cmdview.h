//
// 2017-12-17, jjuiddong
// Command View
//
#pragma once


class cCmdView : public framework::cDockWindow
{
public:
	cCmdView(const string &name);
	virtual ~cCmdView();

	bool Init(graphic::cRenderer &renderer);
	virtual void OnRender(const float deltaSeconds) override;


public:
	struct sCmd
	{
		enum Enum {
			NONE, 
			TRIANGLE, 
			BOX, 
			BOX2, 
			SPHERE,
			DIRECTION, 
			COLLISION, 
			CAMERA, 
			GROUND,
		};

		Enum cmd;
		StrId id;
		StrId arg1;
		StrId arg2;
		StrId arg3;
		StrId arg4;
	};

	struct sSymbol
	{
		StrId type;
		Vector3 val1;
		Vector3 val2;
		Vector3 val3;
		Vector4 val4;
	};


protected:
	bool Parse();
	int ParseLine(const char *str, const int prevLineType, OUT string &outVarName);
	bool ParseFunction(const sCmd::Enum func, const char *str);
	const char* GetLine(const char *str, OUT Str256 &out);
	const char* Str(const char *str, OUT StrId &out);
	const char* Number(const char *str, OUT StrId &out);
	const char* Match(const char *str, const char c);
	bool IsNumber(const char *str);
	sCmd::Enum GetFunctionType(const StrId &str);
	bool Read(const char *fileName);
	bool Write(const char *fileName);


public:
	bool m_isUpdateCamera;
	String<char, 2048> m_text;
	vector<sCmd> m_cmds;
	map<StrId, sSymbol> m_vars;
};
