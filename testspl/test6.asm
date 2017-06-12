.386
.model flat,stdcall
option casemap:none
include msvcrt.inc
includelib msvcrt.lib
printf  proto C:dword,:dword
.data
lb_write_int db '%d',0
lb_writeln_int db '%d',0ah,0dh,0
lb_write_real db '%lf',0
lb_writeln_real db '%lf',0ah,0dh,0
lb_tmp db 0, 0, 0, 0, 0, 0, 0, 0
lb_read_int db '%d',0
lb_read_real db '%f',0

.code
main PROC
mov ecx, esp
sub esp, 12
mov eax, 0
push eax
mov eax, 0
mov ebx, 0
sub eax, ebx
mov ebx, 4
imul eax,ebx
mov edi, -8
add edi, eax
mov esi, ecx
add esi, edi
mov eax, [esi]; calculate ExpId 
pop eax
mov [esi-0], eax
mov eax, 0
push eax
mov eax, 0
mov ebx, 0
sub eax, ebx
mov ebx, 4
imul eax,ebx
mov edi, -8
add edi, eax
mov esi, ecx
add esi, edi
mov eax, [esi]; calculate ExpId 
pop eax
mov [esi-0], eax
mov eax, 0
mov ebx, 0
sub eax, ebx
mov ebx, 4
imul eax,ebx
mov edi, -8
add edi, eax
mov esi, ecx
add esi, edi
mov eax, [esi]; calculate ExpId 
pusha
invoke printf,offset lb_writeln_int, eax
popa
mov eax, 0
mov ebx, 0
sub eax, ebx
mov ebx, 4
imul eax,ebx
mov edi, -8
add edi, eax
mov esi, ecx
add esi, edi
mov eax, [esi]; calculate ExpId 
pusha
invoke printf,offset lb_writeln_int, eax
popa
mov eax, 0
push eax
mov edi, -12
mov esi, ecx
add esi, edi
mov eax, [esi]; calculate ExpId 
pop eax
mov [esi-0], eax
mov eax, 0
push eax
_LABEL_0:
mov edi, -12
mov esi, ecx
add esi, edi
mov eax, [esi]; calculate ExpId 
pop ebx
cmp eax, ebx
ja _LABEL_1
mov edi, -12
mov esi, ecx
add esi, edi
mov eax, [esi]; calculate ExpId 
push eax
mov eax, 0
push eax
pop ebx
pop eax
sub eax, ebx
mov ebx, 0
sub eax, ebx
mov ebx, 4
imul eax,ebx
mov edi, -8
add edi, eax
mov esi, ecx
add esi, edi
mov eax, [esi]; calculate ExpId 
push eax
mov edi, -12
mov esi, ecx
add esi, edi
mov eax, [esi]; calculate ExpId 
push eax
mov eax, 0
push eax
pop ebx
pop eax
sub eax, ebx
mov ebx, 0
sub eax, ebx
mov ebx, 4
imul eax,ebx
mov edi, -8
add edi, eax
mov esi, ecx
add esi, edi
mov eax, [esi]; calculate ExpId 
push eax
pop ebx
pop eax
add eax, ebx
push eax
mov edi, -12
mov esi, ecx
add esi, edi
mov eax, [esi]; calculate ExpId 
mov ebx, 0
sub eax, ebx
mov ebx, 4
imul eax,ebx
mov edi, -8
add edi, eax
mov esi, ecx
add esi, edi
mov eax, [esi]; calculate ExpId 
pop eax
mov [esi-0], eax
mov edi, -12
mov esi, ecx
add esi, edi
mov eax, [esi]; calculate ExpId 
mov ebx, 0
sub eax, ebx
mov ebx, 4
imul eax,ebx
mov edi, -8
add edi, eax
mov esi, ecx
add esi, edi
mov eax, [esi]; calculate ExpId 
pusha
invoke printf,offset lb_writeln_int, eax
popa
mov edi, -12
mov esi, ecx
add esi, edi
mov eax, [esi]; calculate ExpId 
inc eax
mov [esi-0], eax
jmp _LABEL_0
_LABEL_1:
add esp, 12
ret
main ENDP
END main

