
#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(HIW"�n�H�d"NOR"-"HIG"�[�j��"NOR, ({ "super nice guy card", "card" }));

    set_weight(1);

    if( !clonep() ) {
        set("base_unit", "�i");
        set("base_value", 978);
        set("base_weight", 1);
        set("long", 
@LONG
�~�w�w�s�w�w�w�w�w�w�w�s�w�w��
�x��95�x  �n�H������  �xD-40�x
�u�w�w�r�w�w�w�w�w�w�w�r�w�w�t
�x�������������������������ߢx
�x��      �A�O�n�H�A�i�O..���x
�x�����n���F�ڰڰڰڡ�    ���x
�x��  <��>         ��~    ���x
�x��    \         /��\    ���x
�x��    /�@        ||     ���x
�x��                      ���x
�x��������������������������x
�u�w�w�w�w�w�w�w�w�w�w�w�w�w�t
�x �b�j�x��ի�`���������A �x
�x �i���O���X�F�\�h�H����� �x
�U �A�ϱo�ѤU���p�ѹꪺ�H�V �U
�x �ӶV��....               �x
���w�w�w�w�w�w�w�w�w�w�w�w�w��
LONG);
    }
    setup();

}
