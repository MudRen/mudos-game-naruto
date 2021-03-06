#include <ansi.h>
#define N 5
#define TIME 180
#define MOVE "/world/area/jail.c"
inherit ITEM;

mixed *NUM;
mixed *ASK;

string symbol = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890=[]\\;/!@#$%^&*(){}|:<>?";

mixed *getASK() { return ASK; }

void INIT_NUM()
{
    int i, j;

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

    // 要求記憶體
    ASK = allocate(N);
    for(i=0;i<N;i++) {
        ASK[i] = random(10);
    }
}

void create()
{
    set_name("【"HIM"孰不可忍"NOR"】檢舉玩家"NOR, ({ "go away", "away" }));
    set_weight(1000);

    if( !clonep() ) {
        set("unit", "顆");
        set("value", -1);
        set("long", "可以讓你當起正義的警察，用來檢舉某玩家是否違反善良風俗，當然\n"
                "被誤認的玩家，是可以得到一些獎賞的。在使用後，系統會記錄起來\n"
                "，若有過度濫用的玩家，將會受到處罰。\n"
                "使用方式： use away to <玩家>\n" );
    }

    INIT_NUM();

    setup();
}

string getAsk()
{
    int i, j, k, rnd;
    string msg = "";
    for(i=0;i<5;i++) {
        for(j=0;j<N;j++) {
            for(k=0;k<5;k++) {
                if( NUM[ASK[j]][i][k] ) {
                    rnd = random(sizeof(symbol));
                    msg += symbol[rnd..rnd];
                } else msg += " ";
            }
            msg += "  ";
        }
        msg += "\n";
    }
    return msg;
}

int relay_say(object me, string arg)
{
    int i;
    string ans = "";

    if( me == query("target") ) {
        for(i=0;i<N;i++) ans += ASK[i];
        if( arg == ans ) {
            remove_call_out("doAsk");
//           tell_object(me, HIY"你答對了！你銀行進帳 " + (this_object()->query("value")/2)+ " 兩銀子！\n"NOR);
           tell_object(me, HIY"你答對了！你銀行進帳 50000 兩銀子！\n"NOR);
//            me->add("bank", this_object()->query("value")/2);
            me->add("bank", 50000);
            query("target")->interrupt(query("target"), "*");
            query("user")->interrupt(query("user"), "*");
            destruct(this_object());
        } else {
            tell_object(me, "你所回答的並不正確！\n");
        }
    }
    return 0;
}

void doAsk()
{
    query("target")->start_busy(10);
    query("user")->start_busy(10);
    this_object()->add("timer", 10);

    if( this_object()->query("timer") > TIME ) {
        tell_object(query("target"), HIR"你超過時間了...\n"NOR);
        query("target")->interrupt(query("target"), "*");
        query("user")->interrupt(query("user"), "*");
        query("target")->move(MOVE);
        destruct(this_object());
        return;
    }

    if( TIME - this_object()->query("timer") < 10 )
        tell_object(query("target"), HIR"你還剩下不到十秒的時間...\n"NOR);
    else if( TIME - this_object()->query("timer") < 20 )
        tell_object(query("target"), HIR"你還剩下不到二十秒的時間...\n"NOR);
    else if( TIME - this_object()->query("timer") < 30 )
        tell_object(query("target"), HIR"你還剩下不到三十秒的時間...\n"NOR);
    else if( TIME - this_object()->query("timer") < 60 )
        tell_object(query("target"), HIR"你還剩下不到六十秒的時間...\n"NOR);

    tell_object(query("target"), getAsk() );
    tell_object(query("target"), "\n請用 say 說出上面的數字...\n\n");

    call_out("doAsk", 10, this_object());
}

int do_use(object me, string arg)
{
object obj;

    if( !environment(me) ) return 0;
    if( !arg ) return 0;
    if( this_object()->query("timer") ) return 0;

    if( !objectp(obj = present(arg, environment(me))))
    return notify_fail("沒有這個人...\n");
    if( !userp(obj) ) return notify_fail("你只能對玩家使用...\n");
    
    if( me->is_busy() || me->is_fighting() ) return notify_fail("你現在沒空...\n");
    if( obj->is_busy() || obj->is_fighting() ) return notify_fail("對方沒空...\n");
    
    if( environment(me)->is_area() ) {
    int x = me->query("area_info/x_axis"),
    y = me->query("area_info/y_axis");
    if( !area_move(environment(me), this_object(), x, y) ) 
    return notify_fail("使用失敗...\n");
    } else {
    if( !this_object()->move(environment(me)) )
    return notify_fail("使用失敗...\n");
    }

    message_vision(HIW"$N當起了正義警察，似乎覺得$n有違善良風俗的嫌疑...\n"NOR, me, obj);

    this_object()->set("user", me);
    this_object()->set("target", obj);
    this_object()->set("no_get", 1);
    this_object()->set("no_sac", 1);

    log_file("jail", sprintf("[%s] %s(%s) 檢舉 %s(%s) \n", ctime(time())[0..15],
             me->query("name"), me->query_id(), obj->query("name"), obj->query_id()) );


    me->start_busy(1);
    obj->start_busy(1);
    this_object()->set("timer",1);
    call_out("doAsk", 1, this_object());
}
