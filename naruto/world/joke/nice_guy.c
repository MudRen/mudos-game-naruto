#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(HIW"�n�H�d"NOR, ({ "nice guy card", "card" }));

    set_weight(1);

    if( !clonep() ) {
        set("base_unit", "�i");
        set("base_value", 78);
        set("base_weight", 1);
        set("long", 
@LONG
 �~�w�w�s�w�w�w�w�w�w�w�s�w�w��
 �x�����x  �n�H���ŧP  �xF-99�x
 �u�w�w�r�w�w�w�w�w�w�w�r�w�w�t
 �x�������������������������ߢx
 �x�� �n�H!         �n�H!  ���x
 �x��         �n�H!        ���x
 �x��    �n�H!  ///   �n�H!���x
 �x��       ___OTZ___      ���x
 �x��������������������������x
 �u�w�w�w�w�w�w�w�w�w�w�w�w�w�t
 �x "�藍�_�A�A�u�O�@�Ӧn�H" �x
 ���w�w�w�w�w�w�w�w�w�w�w�w�w��
LONG);
    }
    setup();

}
