// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� IP2LOCDLL_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// IP2LOCDLL_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef IP2LOCDLL_EXPORTS
#define IP2LOCDLL_API __declspec(dllexport)
#else
#define IP2LOCDLL_API __declspec(dllimport)
#endif

// �����Ǵ� IP2LOC-dll.dll ������
class IP2LOCDLL_API CIP2LOCdll {
public:
	CIP2LOCdll(void);
	// TODO:  �ڴ�������ķ�����
	bool init(char* binPath);
	char* Query(char* ipStr);
	~CIP2LOCdll(void);
private:
	char resultStr[800];
};

extern IP2LOCDLL_API int nIP2LOCdll;

IP2LOCDLL_API int fnIP2LOCdll(void);
