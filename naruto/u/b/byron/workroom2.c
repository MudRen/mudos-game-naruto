#include <ansi.h>
#include <room.h>

// �]��INN�̡A�|�۰ʦ����D�԰ϡA�åB�O�����I
inherit INN;
 
void create() 
{
    set("short", "���U�t�O-�D�F��");
    set("long", @LONG
�@�Ӥ��O�ܤj���D�F�A�~���٦b�U���D�`���N�A���O�o�̦��G���x��@�˷ŷx�F�\�h�C
LONG);
    set("exits", ([ /* sizeof() == 2 */
        "south" : "/u/b/byron/workroom",  
    ]));
    setup();
    load_object("/daemon/board/byron2");
}
