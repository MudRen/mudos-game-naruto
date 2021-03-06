#include <ansi.h>
#include <room.h>
#define N 6

inherit INN;

string symbol = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890=[]\\;/!@#$%^&*(){}|:<>?";

mixed *NUM;

void create()
{
    int i, j;

    set("short", "精靈大門");
    set("long", "上面刻著許多文字的大門，門的上方有一個天井，正好讓空中的\n"
                "月光照射在門上，每當那些文字吸收了足夠的月光，便會發出藍色亮\n"
                "光，所出現的文字還有所不同，非常的奇妙。\n"
                "你可以看看門上(seedoor)所顯示的文字是在說什麼。\n");

    set("exits", ([
        "south" : ([ "filename": _DIR_AREA_"wizard/wizard.c",
                      "x_axis": 26,
                      "y_axis": 23,
                 ]),
        "east" : ([ "filename": _DIR_AREA_"wizard/wizard.c",
                      "x_axis": 29,
                      "y_axis": 20,
                 ]),
        "north" : ([ "filename": _DIR_AREA_"wizard/wizard.c",
                      "x_axis": 26,
                      "y_axis": 17,
                 ]),
        "west" : ([ "filename": _DIR_AREA_"wizard/wizard.c",
                      "x_axis": 23,
                      "y_axis": 20,
                 ]),
    ]));
    set("objects", ([
        __DIR__"npc/fei.c" : 1,
    ]));
    setup();

    // 要求記憶體
    NUM = allocate(10);
    for(i=0;i<10;i++) {
        NUM[i] = allocate(5);
        for(j=0;j<5;j++)
            NUM[i][j] = allocate(5);
    }
    NUM[0][0] = ({ 1,1,1,1,1, });
    NUM[0][1] = ({ 1,0,0,0,1, });
    NUM[0][2] = ({ 1,0,0,0,1, });
    NUM[0][3] = ({ 1,0,0,0,1, });
    NUM[0][4] = ({ 1,1,1,1,1, });

    NUM[1][0] = ({ 1,1,1,0,0, });
    NUM[1][1] = ({ 0,0,1,0,0, });
    NUM[1][2] = ({ 0,0,1,0,0, });
    NUM[1][3] = ({ 0,0,1,0,0, });
    NUM[1][4] = ({ 1,1,1,1,1, });

    NUM[2][0] = ({ 1,1,1,1,1, });
    NUM[2][1] = ({ 0,0,0,0,1, });
    NUM[2][2] = ({ 1,1,1,1,1, });
    NUM[2][3] = ({ 1,0,0,0,0, });
    NUM[2][4] = ({ 1,1,1,1,1, });

    NUM[3][0] = ({ 1,1,1,1,1, });
    NUM[3][1] = ({ 0,0,0,0,1, });
    NUM[3][2] = ({ 1,1,1,1,1, });
    NUM[3][3] = ({ 0,0,0,0,1, });
    NUM[3][4] = ({ 1,1,1,1,1, });

    NUM[4][0] = ({ 1,0,0,0,1, });
    NUM[4][1] = ({ 1,0,0,0,1, });
    NUM[4][2] = ({ 1,1,1,1,1, });
    NUM[4][3] = ({ 0,0,0,0,1, });
    NUM[4][4] = ({ 0,0,0,0,1, });

    NUM[5][0] = ({ 1,1,1,1,1, });
    NUM[5][1] = ({ 1,0,0,0,0, });
    NUM[5][2] = ({ 1,1,1,1,1, });
    NUM[5][3] = ({ 0,0,0,0,1, });
    NUM[5][4] = ({ 1,1,1,1,1, });

    NUM[6][0] = ({ 1,1,1,1,1, });
    NUM[6][1] = ({ 1,0,0,0,0, });
    NUM[6][2] = ({ 1,1,1,1,1, });
    NUM[6][3] = ({ 1,0,0,0,1, });
    NUM[6][4] = ({ 1,1,1,1,1, });

    NUM[7][0] = ({ 1,1,1,1,1, });
    NUM[7][1] = ({ 1,0,0,0,1, });
    NUM[7][2] = ({ 0,0,0,0,1, });
    NUM[7][3] = ({ 0,0,0,0,1, });
    NUM[7][4] = ({ 0,0,0,0,1, });

    NUM[8][0] = ({ 1,1,1,1,1, });
    NUM[8][1] = ({ 1,0,0,0,1, });
    NUM[8][2] = ({ 1,1,1,1,1, });
    NUM[8][3] = ({ 1,0,0,0,1, });
    NUM[8][4] = ({ 1,1,1,1,1, });

    NUM[9][0] = ({ 1,1,1,1,1, });
    NUM[9][1] = ({ 1,0,0,0,1, });
    NUM[9][2] = ({ 1,1,1,1,1, });
    NUM[9][3] = ({ 0,0,0,0,1, });
    NUM[9][4] = ({ 1,1,1,1,1, });
}

void init()
{
    add_action("do_recall", "recall");
    add_action("do_leave", "seedoor");
}

int do_recall(string arg)
{
    tell_object(this_player(), "在這裡不能使用這個功\能。\n");
    return 1;
}

void create_ask(object who)
{
    int i;
    string ask = "";
    for(i=0;i<N;i++) ask += ""+random(10);
    who->set_temp("jail", ask);
}

void show_ask(object who)
{
    int i, j, k, rnd;
    string numbers, msg = "";

    if( !objectp(who) ) return;
    numbers = who->query_temp("jail");

    for(i=0;i<5;i++) {
        for(j=0;j<N;j++) {
            for(k=0;k<5;k++ ) {
                if( NUM[atoi(numbers[j..j])][i][k] ) {
                    rnd = random(sizeof(symbol));
                    msg += symbol[rnd..rnd];
                } else msg += " ";
            }
            msg += "  ";
        }
        msg += "\n";
    }
    msg += "\n";
    tell_object(who, msg);
}

void do_ask(string arg, object who)
{
    object room;

    room = load_object("/world/area/wizard/elf_house.c");

    if( !objectp(room) || arg != who->query_temp("jail") ) {
        tell_object(who, "你的答案不正確...\n");
        return;
    }
    if( !area_move(room, who, 15, 17) ) {
        message_vision("但是大門一動也不動。\n", who);
        return;
    }
    who->delete_temp("ELF_HOUSE");
    message_vision(CYN"大門漸漸敞開了，$N快步的走了進去。\n"NOR, who);
    return;
}

int do_leave(string arg)
{
    create_ask(this_player());
    show_ask(this_player());
    tell_object(this_player(),"門上出現幾行字："HIG"想要進入精靈之屋，必須正確回答數字..."NOR);
    input_to("do_ask", this_player());
    return 1;
}
