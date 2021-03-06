#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(HIC"刮刮樂彩券"NOR, ({ "lotto" }));

    if( !clonep() ) {
        set("base_unit", "張");
        set("base_value", 50);
        set("base_weight", 1);
        set("no_box", 1);
        set("long", "一張刮刮樂彩券，你可以括(use)開上面的銀漆，看是不是中獎了。\n"
                    "(一次括全部：use lotto to all)\n"
                    "第一特獎： 1,000,000 元\n"
                    "    頭獎：   500,000 元\n"
                    "    貳獎：   150,000 元\n"
                    "    參獎：    50,000 元\n"
                    "    肆獎：     2,000 元\n"
                    "    普獎：       200 元\n" );
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

    message_vision("$N拔出插在鼻孔裡的手指頭，在$n上畫來畫去。\n", me, this_object());

    if( arg && arg == "all" ) {
        int i, amount = this_object()->query_amount();
        if( amount > 9999 ) {
            tell_object(me, "你有太多彩券了，你只括了一萬張...\n");
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
        message_vision("$N中了第一特獎：100萬元 " + record[1] + " 張...\n", me);
        me->add("bank", 1000000*record[1]);
    }

    if( record[2] > 0 ) {
        message_vision("$N中了頭獎：50萬元 " + record[2] + " 張...\n", me);
        me->add("bank", 500000*record[2]);
    }

    if( record[3] > 0 ) {
        message_vision("$N中了貳獎：15萬元 " + record[3] + " 張...\n", me);
        me->add("bank", 150000*record[3]);
    }

    if( record[4] > 0 ) {
        message_vision("$N中了參獎：5萬元 " + record[4] + " 張...\n", me);
        me->add("bank", 50000*record[4]);
    }

    if( record[5] > 0 ) {
        message_vision("$N中了肆獎：2千元 " + record[5] + " 張...\n", me);
        me->add("bank", 2000*record[5]);
    }

    if( record[6] > 0 ) {
        message_vision("$N中了普獎：200元 " + record[6] + " 張...\n", me);
        me->add("bank", 200*record[6]);
    }

    if( record[0] > 0 ) {
        message_vision("$N括到了銘謝惠顧" + record[0] + "張...\n", me);
    }

    // 個數減少
    if( !this_object()->query_amount() ) destruct(this_object());

    return 1;
}
