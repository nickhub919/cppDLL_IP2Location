// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 IP2LOCDLL_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// IP2LOCDLL_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#ifdef IP2LOCDLL_EXPORTS
#define IP2LOCDLL_API __declspec(dllexport)
#else
#define IP2LOCDLL_API __declspec(dllimport)
#endif

// 此类是从 IP2LOC-dll.dll 导出的
class IP2LOCDLL_API CIP2LOCdll {
public:
	CIP2LOCdll(void);
	// TODO:  在此添加您的方法。
	bool init(char* binPath);
	char* Query(char* ipStr);
	~CIP2LOCdll(void);
private:
	char resultStr[800];
};

extern IP2LOCDLL_API int nIP2LOCdll;

IP2LOCDLL_API int fnIP2LOCdll(void);
