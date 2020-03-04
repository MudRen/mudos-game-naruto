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

    // �n�D�O����
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

    // �n�D�O����
    ASK = allocate(N);
    for(i=0;i<N;i++) {
        ASK[i] = random(10);
    }
}

void create()
{
    set_name("�i"HIM"�E���i��"NOR"�j���|���a"NOR, ({ "go away", "away" }));
    set_weight(1000);

    if( !clonep() ) {
        set("unit", "��");
        set("value", -1);
        set("long", "�i�H���A��_���q��ĵ��A�Ψ����|�Y���a�O�_�H�ϵ��}���U�A��M\n"
                "�Q�~�{�����a�A�O�i�H�o��@�Ǽ��઺�C�b�ϥΫ�A�t�η|�O���_��\n"
                "�A�Y���L���ݥΪ����a�A�N�|����B�@�C\n"
                "�ϥΤ覡�G use away to <���a>\n" );
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
//           tell_object(me, HIY"�A����F�I�A�Ȧ�i�b " + (this_object()->query("value")/2)+ " ��Ȥl�I\n"NOR);
           tell_object(me, HIY"�A����F�I�A�Ȧ�i�b 50000 ��Ȥl�I\n"NOR);
//            me->add("bank", this_object()->query("value")/2);
            me->add("bank", 50000);
            query("target")->interrupt(query("target"), "*");
            query("user")->interrupt(query("user"), "*");
            destruct(this_object());
        } else {
            tell_object(me, "�A�Ҧ^�����ä����T�I\n");
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
        tell_object(query("target"), HIR"�A�W�L�ɶ��F...\n"NOR);
        query("target")->interrupt(query("target"), "*");
        query("user")->interrupt(query("user"), "*");
        query("target")->move(MOVE);
        destruct(this_object());
        return;
    }

    if( TIME - this_object()->query("timer") < 10 )
        tell_object(query("target"), HIR"�A�ٳѤU����Q���ɶ�...\n"NOR);
    else if( TIME - this_object()->query("timer") < 20 )
        tell_object(query("target"), HIR"�A�ٳѤU����G�Q���ɶ�...\n"NOR);
    else if( TIME - this_object()->query("timer") < 30 )
        tell_object(query("target"), HIR"�A�ٳѤU����T�Q���ɶ�...\n"NOR);
    else if( TIME - this_object()->query("timer") < 60 )
        tell_object(query("target"), HIR"�A�ٳѤU���줻�Q���ɶ�...\n"NOR);

    tell_object(query("target"), getAsk() );
    tell_object(query("target"), "\n�Х� say ���X�W�����Ʀr...\n\n");

    call_out("doAsk", 10, this_object());
}

int do_use(object me, string arg)
{
object obj;

    if( !environment(me) ) return 0;
    if( !arg ) return 0;
    if( this_object()->query("timer") ) return 0;

    if( !objectp(obj = present(arg, environment(me))))
    return notify_fail("�S���o�ӤH...\n");
    if( !userp(obj) ) return notify_fail("�A�u��缾�a�ϥ�...\n");
    
    if( me->is_busy() || me->is_fighting() ) return notify_fail("�A�{�b�S��...\n");
    if( obj->is_busy() || obj->is_fighting() ) return notify_fail("���S��...\n");
    
    if( environment(me)->is_area() ) {
    int x = me->query("area_info/x_axis"),
    y = me->query("area_info/y_axis");
    if( !area_move(environment(me), this_object(), x, y) ) 
    return notify_fail("�ϥΥ���...\n");
    } else {
    if( !this_object()->move(environment(me)) )
    return notify_fail("�ϥΥ���...\n");
    }

    message_vision(HIW"$N��_�F���qĵ��A���Gı�o$n���H���}���U������...\n"NOR, me, obj);

    this_object()->set("user", me);
    this_object()->set("target", obj);
    this_object()->set("no_get", 1);
    this_object()->set("no_sac", 1);

    log_file("jail", sprintf("[%s] %s(%s) ���| %s(%s) \n", ctime(time())[0..15],
             me->query("name"), me->query_id(), obj->query("name"), obj->query_id()) );


    me->start_busy(1);
    obj->start_busy(1);
    this_object()->set("timer",1);
    call_out("doAsk", 1, this_object());
}
