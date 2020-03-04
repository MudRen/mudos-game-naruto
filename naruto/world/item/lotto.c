#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(HIC"���ֱm��"NOR, ({ "lotto" }));

    if( !clonep() ) {
        set("base_unit", "�i");
        set("base_value", 50);
        set("base_weight", 1);
        set("no_box", 1);
        set("long", "�@�i���ֱm��A�A�i�H�A(use)�}�W�����Ⱥ��A�ݬO���O�����F�C\n"
                    "(�@���A�����Guse lotto to all)\n"
                    "�Ĥ@�S���G 1,000,000 ��\n"
                    "    �Y���G   500,000 ��\n"
                    "    �L���G   150,000 ��\n"
                    "    �Ѽ��G    50,000 ��\n"
                    "    �v���G     2,000 ��\n"
                    "    �����G       200 ��\n" );
    }
    setup();
}

int do_rand()
{
    switch( random(1500000) ) {
        case 1001: return 1;
        case 1002..1021: return 2;
        case 1022..1081: return 3;
        case 1082..1301: return 4;
        case 1302..2001: return 5;
        case 2002..4501: return 6;
        default: return 0;
    }
}

int do_use(object me, string arg)
{
    mapping record = ([ 0:0, 1:0, 2:0, 3:0, 4:0, 5:0, 6:0, ]);

    if( !objectp(me) ) return 0;

    message_vision("$N�ޥX���b��ո̪�����Y�A�b$n�W�e�ӵe�h�C\n", me, this_object());

    if( arg && arg == "all" ) {
        int i, amount = this_object()->query_amount();
        if( amount > 9999 ) {
            tell_object(me, "�A���Ӧh�m��F�A�A�u�A�F�@�U�i...\n");
            amount = 10000;
        }
        i = amount;
        while( i-- ) record[do_rand()] += 1;
        this_object()->add_amount(-amount);
    } else {
        record[do_rand()] += 1;
        this_object()->add_amount(-1);
    }

    if( record[1] > 0 ) {
        message_vision("$N���F�Ĥ@�S���G100�U�� " + record[1] + " �i...\n", me);
        me->add("bank", 1000000*record[1]);
    }

    if( record[2] > 0 ) {
        message_vision("$N���F�Y���G50�U�� " + record[2] + " �i...\n", me);
        me->add("bank", 500000*record[2]);
    }

    if( record[3] > 0 ) {
        message_vision("$N���F�L���G15�U�� " + record[3] + " �i...\n", me);
        me->add("bank", 150000*record[3]);
    }

    if( record[4] > 0 ) {
        message_vision("$N���F�Ѽ��G5�U�� " + record[4] + " �i...\n", me);
        me->add("bank", 50000*record[4]);
    }

    if( record[5] > 0 ) {
        message_vision("$N���F�v���G2�d�� " + record[5] + " �i...\n", me);
        me->add("bank", 2000*record[5]);
    }

    if( record[6] > 0 ) {
        message_vision("$N���F�����G200�� " + record[6] + " �i...\n", me);
        me->add("bank", 200*record[6]);
    }

    if( record[0] > 0 ) {
        message_vision("$N�A��F���´f�U" + record[0] + "�i...\n", me);
    }

    // �Ӽƴ��
    if( !this_object()->query_amount() ) destruct(this_object());

    return 1;
}
