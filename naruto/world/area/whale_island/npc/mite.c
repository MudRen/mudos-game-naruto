//�̯S mite.c -Tmr

#include <npc.h>

inherit F_VILLAGER;
inherit F_VENDOR;

void create()
{
        set_name("�̯S�E�I�O�h", ({ "mite fulishi", "mite", "fulishi" }) );
        set_race("human");
         set_attr("int", 30 );
        set_attr("str", 19);
        set_attr("cor", 17);
        set_attr("cps", 15);
        set_attr("dex", 18);
          set("gender", "female");
          set("age", 25);
        set("long",@long
�̯S���o���s�����D�H�A�M�o�����ˤ@�_�޲z���n�X�~���ɶ��F�C��
�S�d�ۤ@�Y�N�R���u�v�A�@�������Q�G�G���Q�������C                                                     
long
);


    set_goods(1, "wp", 15, 10, 15);

        set("chat_chance", 5);
        set("chat_msg", ({
                "�̯S���z�ۮ�l���ۻ��֪��q���C\n",
                "�̯S�L���a�ݧA�G�u�Q�n�I�Ǥ���ܡH�v \n",
                "�̯S��F�橱���f�A���G�b���ݽ֦^�ӡI�H \n",
        }));
        setup();
}

