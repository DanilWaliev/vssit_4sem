.686
.model FLAT, C

includelib msvcrt.lib

; Объявляем внешние функции из стандартной библиотеки C
extern time:near        
extern srand:near       
extern rand:near        

.data
    initialized DWORD 0  ; Флаг инициализации

.code
GET_RANDOM PROC C
    ; Проверяем, инициализирован ли генератор
    CMP initialized, 0
    JNE generate        ; Если да, переходим к генерации числа

    ; Инициализация генератора случайных чисел
    PUSH 0              ; Передаём NULL (0) в функцию time
    CALL time           ; Вызываем time(NULL) -> EAX = текущее время
    ADD ESP, 4          ; Очищаем стек (cdecl)

    PUSH EAX            ; Передаём seed (текущее время) в srand
    CALL srand          ; srand(time(NULL))
    ADD ESP, 4

    MOV initialized, 1  ; Помечаем генератор как инициализированный

generate:
    ; Генерируем случайное число через rand()
    CALL rand           ; EAX = случайное число (0..32767)

    ; Приводим число к диапазону 0..100
    XOR EDX, EDX        ; Обнуляем EDX для деления
    MOV ECX, 101        ; Делитель = 101 (0..100)
    DIV ECX             ; EDX = остаток от деления (0..100)

    ; Преобразуем в диапазон -50..50
    MOV EAX, EDX        ; EAX = 0..100
    SUB EAX, 50         ; EAX = -50..50

    RET                 ; Возвращаем результат через EAX
GET_RANDOM ENDP

END