.686
.model FLAT, C

includelib msvcrt.lib

; ��������� ������� ������� �� ����������� ���������� C
extern time:near        
extern srand:near       
extern rand:near        

.data
    initialized DWORD 0  ; ���� �������������

.code
GET_RANDOM PROC C
    ; ���������, ��������������� �� ���������
    CMP initialized, 0
    JNE generate        ; ���� ��, ��������� � ��������� �����

    ; ������������� ���������� ��������� �����
    PUSH 0              ; ������� NULL (0) � ������� time
    CALL time           ; �������� time(NULL) -> EAX = ������� �����
    ADD ESP, 4          ; ������� ���� (cdecl)

    PUSH EAX            ; ������� seed (������� �����) � srand
    CALL srand          ; srand(time(NULL))
    ADD ESP, 4

    MOV initialized, 1  ; �������� ��������� ��� ������������������

generate:
    ; ���������� ��������� ����� ����� rand()
    CALL rand           ; EAX = ��������� ����� (0..32767)

    ; �������� ����� � ��������� 0..100
    XOR EDX, EDX        ; �������� EDX ��� �������
    MOV ECX, 101        ; �������� = 101 (0..100)
    DIV ECX             ; EDX = ������� �� ������� (0..100)

    ; ����������� � �������� -50..50
    MOV EAX, EDX        ; EAX = 0..100
    SUB EAX, 50         ; EAX = -50..50

    RET                 ; ���������� ��������� ����� EAX
GET_RANDOM ENDP

END