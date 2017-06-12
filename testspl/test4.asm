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
go:
sub esp, 12
mov edi, 8
mov esi, ecx
add esi, edi
mov eax, [esi]; calculate ExpId 
push eax
mov eax, 0
push eax
pop ebx
pop eax
cmp eax, ebx
mov eax, 0
setg al
cmp eax, 0
je _LABEL_0
push eax
mov edi, 8
mov esi, ecx
add esi, edi
mov eax, [esi]; calculate ExpId 
push eax
mov eax, 0
push eax
pop ebx
pop eax
sub eax, ebx
push eax
mov edi, 4
mov esi, ecx
add esi, edi
mov eax, [esi]; calculate ExpId 
push eax
push ecx
mov ecx, esp
call go
pop ecx
mov edi, 4
mov esi, ecx
add esi, edi
mov eax, [esi]; calculate ExpId 
pop eax
mov [esi],eax
pop eax
pop eax
push eax
mov edi, 12
mov esi, ecx
add esi, edi
mov eax, [esi]; calculate ExpId 
pop eax
mov [esi-0], eax
jmp _LABEL_1
_LABEL_0:
mov eax, 0
push eax
mov edi, 12
mov esi, ecx
add esi, edi
mov eax, [esi]; calculate ExpId 
pop eax
mov [esi-0], eax
_LABEL_1:
mov edi, 4
mov esi, ecx
add esi, edi
mov eax, [esi]; calculate ExpId 
push eax
mov edi, 12
mov esi, ecx
add esi, edi
mov eax, [esi]; calculate ExpId 
push eax
pop ebx
pop eax
add eax, ebx
push eax
mov edi, 4
mov esi, ecx
add esi, edi
mov eax, [esi]; calculate ExpId 
pop eax
mov [esi-0], eax
mov edi, -12
mov esi, ecx
mov eax, [esi]
mov esi, eax
add esi, edi
mov eax, [esi]; calculate ExpId 
push eax
mov edi, 12
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
mov eax, [esi]
mov esi, eax
add esi, edi
mov eax, [esi]; calculate ExpId 
pop eax
mov [esi-0], eax
add esp, 12
ret
main PROC
mov ecx, esp
sub esp, 12
mov eax, 0
push eax
mov edi, -12
mov esi, ecx
add esi, edi
mov eax, [esi]; calculate ExpId 
pop eax
mov [esi-0], eax
push eax
mov eax, 0
push eax
mov edi, -12
mov esi, ecx
add esi, edi
mov eax, [esi]; calculate ExpId 
push eax
push ecx
mov ecx, esp
call go
pop ecx
mov edi, -12
mov esi, ecx
add esi, edi
mov eax, [esi]; calculate ExpId 
pop eax
mov [esi],eax
pop eax
pop eax
push eax
mov edi, -8
mov esi, ecx
add esi, edi
mov eax, [esi]; calculate ExpId 
pop eax
mov [esi-0], eax
mov edi, -8
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
pusha
invoke printf,offset lb_writeln_int, eax
popa
add esp, 12
ret
main ENDP
END main

