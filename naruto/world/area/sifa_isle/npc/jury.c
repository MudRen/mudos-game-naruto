#include <ansi.h>
#include <npc.h>

inherit F_SEASOLDIER;

void create()
{
    set_name("���f��", ({ "jury" }) );
    set_race("human");
    set_level(40);
    set("title",HIC"�q�k�q"NOR);
    set("nickname",BRED+HIW"�@���@�o�@"NOR);
    set("class", "guard_sea");
    set("camp", "police");
    set("age", 25+random(41));
    set("long", "�@�y���c���H�A�f����������ۡu���o...���o...�v�C�L�N�O�q�k�q\n"
                "�W�����f�έ����@�C�ڻ��q�k�q�W�����f�έ��A���O�Ӧ۲`���j�ʺ�\n"
                "������馨���A�L�̦]���@���l���L�k�A���}���Ӷ·t���ʺ��A�b��\n"
                "�o���f�Ϊ�����u�Q��Q�f�P�N�H�]�Զi�`���j�ʺ��A�]���b�o�q\n"
                "�k�q�W�٨S������@�H��P�L�o���C\n");
    set("chat_chance", 15);
    set("chat_msg", ({
        (: command, "say ���o�I���o�I" :),
    }));
    set("chat_chance_combat", 20);
    set("chat_msg_combat", ({
        (: command, "say ���o�I���o�I" :),
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":100, "amount":1, "p1":60, "p2":100 ]),              // �u��
        ([ "type":"obj", "id":102, "amount":1, "p1":40, "p2":100 ]),              // ��÷
        ([ "type":"wp", "id":55, "amount":1, "p1":80, "p2":100 ]),                // �s�;ԤM
        ([ "type":"wp", "id":52, "amount":1, "p1":1, "p2":450 ]),                 // �}�H�b
        ([ "type":"wp", "id":30, "amount":1, "p1":1, "p2":150 ]),                 // �����ԤM
       ([ "type":"obj", "id":109, "amount":1, "p1":1, "p2":500 ]),               // �i�����ѷƪO
    }) );
    setup();
    carry_object(_DIR_WP_"blade.c")->wield();
    add_temp("apply/attack", 50);
    add_temp("apply/armor", 150);
}
