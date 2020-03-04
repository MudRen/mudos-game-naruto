#include <npc.h>
#include <ansi.h>

inherit F_FIGHTER;

int num=0;

string report_status(object ob)
{
    int ratio;
    if( !ob->query_stat_maximum("hp") ) return "\n";
    ratio = (int)ob->query_stat("hp")*100/(int)ob->query_stat_maximum("hp");
    if( ratio > 80 ) return HIK"["HIG"$N" + HIG + ratio + "%" + HIK"]\n"NOR;
    else if( ratio > 30 ) return HIK"["HIY"$N" + HIY + ratio + "%" + HIK"]\n"NOR;
    else return HIK"["HIR"$N" + HIR + ratio + "%" + HIK"]\n"NOR;
}
void do_check()
{
    if( num > 0) {
        set("chat_chance", 10);
        this_object()->heal_stat("hp", num);
        message_vision("$N"HIW"�q�a�W�߰_�e���ɥR��~���Ӱ��Y���ˮ`�C("HIR+num+HIW")"+report_status(this_object())+""NOR, this_object());
        num = 0;
    }
}
void do_whip(object enemy)
{
    int damage, i;
    object* targets;
    // �S���ĤH
    set("chat_chance", 100);
    enemy = this_object()->query_opponent();
    targets = this_object()->query_enemy();
    if( !enemy ) return;
    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    num = num + 30;
    message_vision("$N"NOR"�q���W�z�X�X�ڰ��Y�ϥX�u"HIY"�h���R"NOR"�v���Y���@�l�르�V�|��I\n"NOR, this_object(), enemy);
    for(i=0;i<sizeof(targets);i++) {
        if( i > 9) break;   // ��Q�ӤH����
        damage = random(401)+150;
        if( random(targets[i]->query_ability("evade")) > 250) {
            message_vision("        $N�T�V�����L�F�����I(0)"+report_status(targets[i])+"", targets[i], this_object());
            this_object()->start_busy(1);
        } else {
            targets[i]->damage_stat("hp", damage, targets[i]);
            message_vision("        $N�Q���Y�����A���W���W�h�F�@�D�˲��C("+damage+")"+report_status(targets[i])+"", targets[i], this_object());
        }
    }
}
void do_flower()
{
    int damage;
    object enemy;
    // �S���ĤH
    set("chat_chance", 100);
    enemy = this_object()->query_opponent();
    if( !enemy ) return;
    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    num = num + 50;
    message_vision("$N"NOR"�Ⱙ�����z�X�A�ܦ����p��j�몺�u"HIR"�K�u�ᤧ�R"NOR"�v�I\n"NOR, this_object(), enemy);
    damage = random(this_object()->query_ability("attack")) - random(enemy->query_ability("defend"));
    if( damage <= 0 || random(enemy->query_ability("wittiness")) > 250) {
        message_vision("        $N�O�F�@�f�\�Ҥ~�N���ۤƸѡI(0)"+report_status(enemy)+"", enemy, this_object());
        this_object()->start_busy(2);
        return;
    }
    enemy->damage_stat("hp", damage, enemy);
    message_vision("        �u�P�v�a�@�n�b$N���W�W�X�@�D��}�A��y����C("+damage+")"+report_status(enemy)+"", enemy, this_object());
    enemy->start_busy(1);
    return;
}
void do_finger()
{
    int damage;
    object enemy;
    // �S���ĤH
    set("chat_chance", 100);
    enemy = this_object()->query_opponent();
    if( !enemy ) return;
    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    num = num + 50;
    message_vision("$N"NOR"�Q���񥭴µ�$n�g�X�u"HIW"����"NOR"�v�I\n"NOR, this_object(), enemy);
    damage = random(151)+50;
    if( random(enemy->query_ability("evade")) > 300) {
        message_vision("        $N�ֳt���{�L�F�����I(0)"+report_status(enemy)+"", enemy, this_object());
        this_object()->start_busy(1);
    } else {
        enemy->damage_stat("hp", damage, enemy);
        message_vision("        $N�u�P�v�a�@�n�Q�����W�X�F�@�D�ˤf�C("+damage+")"+report_status(enemy)+"", enemy, this_object());
    }
    damage = random(151)+50;
    if( random(enemy->query_ability("evade")) > 300) {
        message_vision("        $N�ֳt���{�L�F�����I(0)"+report_status(enemy)+"", enemy, this_object());
        this_object()->start_busy(1);
    } else {
        enemy->damage_stat("hp", damage, enemy);
        message_vision("        $N�u�P�v�a�@�n�Q�����W�X�F�@�D�ˤf�C("+damage+")"+report_status(enemy)+"", enemy, this_object());
    }
    damage = random(151)+50;
    if( random(enemy->query_ability("evade")) > 300) {
       message_vision("        $N�ֳt���{�L�F�����I(0)"+report_status(enemy)+"", enemy, this_object());
        this_object()->start_busy(1);
        return;
    } else {
        enemy->damage_stat("hp", damage, enemy);
        message_vision("        $N�u�P�v�a�@�n�Q�����W�X�F�@�D�ˤf�C("+damage+")"+report_status(enemy)+"", enemy, this_object());
        return;
    }
}
void do_fight()
{
    int damage;
    object enemy;
    // �S���ĤH
    set("chat_chance", 100);
    enemy = this_object()->query_opponent();
    if( !enemy ) return;
    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    num = num + 200;
    message_vision("$N"NOR"���l���a�U�@�I�A�ϥX�˩R����"HIY"�y"HIR+BLINK"�������R"NOR+HIY"�z"NOR"�������Y�W�V�|���K��I\n"NOR,this_object(), enemy);
    damage = random(this_object()->query_ability("attack"))*2 + 100;
    damage -= random(enemy->query_ability("defend"));
    if( damage <= 0 || random(enemy->query_ability("evade")) > 450) {
        message_vision("        $N�v���ݬ�F�����~�׶}���ۡI(0)"+report_status(enemy)+"", enemy, this_object());
        this_object()->start_busy(2);
        return;
    }
    enemy->damage_stat("hp", damage, enemy);
    message_vision("        �u�P�P�v�s��X�n�A$N���w�Q�W�����ۡA��y�p�`�C("+damage+")"+report_status(enemy)+"", enemy, this_object());
    return;
}
void do_clone()
{
    object enemy, item;
    // �S���ĤH
    set("chat_chance", 100);
    enemy = this_object()->query_opponent();
    item = new(__DIR__"wp/spinal.c");
    if( !enemy ) return;
    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    if( this_object()->query_temp("quest/psychical") == 1) {
    return;
    }
    this_object()->add_temp("quest/psychical", 1);
    num = num + 300;
    message_vision("$N"HIW"�I���C�C�Y�_�@���զⰩ�Y�A����ޥX��~�M�O�L�ۤv����հ��I\n"NOR, this_object());
    item->move(this_object());
    do_chat((: command, "wield sword" :));
    return;
}
void create()
{
    set_name("���]�褧��", ({ "wheya gon lon", "lon" }) );
    set_level(60);
    set_class("superior");
    set_race("human");
    set("gender", "male");
    set("age", 85);
    set("title",HIR"���]�ڪ�"NOR);
    set("long",@LONG
���]�ڪ��A�@�ӤK�Q�h�����p���Y�A���O�L�����U�Q�A�|�P���@����
�k���L�L�������C��~���]�ڤH�Q�l���ɪ��˲������d�b���W�A����
�U�B�����j�j�p�p���˲��A���L�o�Ƕ˲��ݦ���αq�����~��������
�A�ڻ����]�ڤH���ئ��~���ɡA��N�ۤv���W�����Y�ޥX�A���M�|��
�ۤv�y���ˮ`�A�ҩޥX���Z���o����H�ߩҼ����ܤơA��@�몺�Z��
�٭n�n�ΡC�]�]���o�ˡA�ҥH���]�@�ڤS�Q�٬��y�c�]�@�ڡz
LONG);
    set("chat_chance", 10);
    set("chat_msg", ({
        (: do_check :),
        (: command, "say ���F�D�H�S�ӭөǪ�...":),
        (: command, "say �ڤH�����h��I�D�H�F�C":),
        (: command, "say �u�n�O�j�D�Y�j�H�U�I�����ȡA�@�w�n�����C":),
    }));
    set("chat_chance_combat", 15);
    set("chat_msg_combat", ({
        (: do_fight :),
        (: do_clone :),
        (: do_flower :),
        (: do_finger :),
        (: do_whip :),
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":28, "amount":1+random(5), "p1":60, "p2":100 ]), // ����
        ([ "type":"obj", "id":78, "amount":1, "p1":100, "p2":100 ]),   // ���]����
        ([ "type":"wp", "id":50, "amount":1, "p1":1, "p2":200 ]),      // �ᰩ�C
        ([ "type":"eq", "id":85, "amount":1, "p1":1, "p2":150 ]),      // �G�L�Э�
    }) );
    setup();
}
void relay_say(object ob, string arg)
{
    if( arg == "�D�H" )  {
        do_chat(({
            (: command, "say �o�̸򯫼q�B�ԨƪL�B����h�A�H�e���O�D�H���a�L�C" :),
            (: command, "say �ڭ̨ӤF����I�_�e���Գ��A���e�̨�a�L�k���q�C" :),
            (: command, "say ���ۥ��O�����ԨƪL���̪��D�ڥ����C" :),
            (: command, "say �N�b�ڭ̩M�D�H��ѭѶˮ�...���M�]�X�@��Ǫ��C" :),
            (: command, "say ���ǩǪ���ڭ̩M�D�H���]�A�N���ڤF���̡C" :),
        }));
        return;
    }
    if( arg == "�Ǫ�" )  {
        do_chat(({
            (: command, "say �e�̦��ۺ�⪺����A�ٮ��ۤ@���M" :),
            (: command, "say �ڭ̳q�٨e�̥s�u�q���Q�v�C" :),
            (: command, "say �e�̲{�b�N�w�~�b�ԨƪL�C" :),
            (: command, "say �����e�̭n�p�ߡC" :),
            (: command, "say �e�̪����]�|���˦����q���q���Q�V�b�̭��C" :),
            (: command, "ah" :),
            (: command, "say �٦�...�ԨƪL�������ⶡ�}�ΡC" :),
            (: command, "say �q���Q�̦n�������@�N����䤤���@���C" :),
            (: command, "say ���n�ݬ�����A���D�o�Ӥ@�w��A�����U���C" :),
        }));
        return;
    }
    if( arg == "�j�D�Y" )  {
        do_chat(({
            (: command, "say �L�O�ڭ̽��]�@�ڪ����H�I" :),
        }));
        return;
    }
    if( arg == "�ڤH" )  {
        do_chat(({
            (: command, "say ��M�N�O�ڭ̽��]�@�ڡI" :),
        }));
        return;
    }
    if( arg == "����" )  {
        if( this_player()->query_temp("quest/tonlight") == 1) {
        do_chat(({
            (: command, "say ���Q�����N���u�����v" :),
            (: command, "say �o�إ������~�H�ӿ�]�O�ڪ������C" :),
        }));
        return;
        } else
        if( this_player()->query_temp("quest/tonlight") == 2) {
            do_chat(({
                (: command, "say ���Q�����ܡH" :),
                (: command, "say ���N�u����v�~�������a�C" :),
            }));
            return;
        }
        this_player()->add_temp("quest/tonlight", 1);
        do_chat(({
            (: command, "say �O�j�D�Y�U�I���ڭ̪����ȡC" :),
            (: command, "say �ؼЬO�ԨƪL�q���Q�Ү����OŢ�C" :),
            (: command, "say �]���o�OŢ�㦳���˪��\��A�ҥH�j�D�Y�j�H�D�`�n�_�C" :),
            (: command, "say �����e�̤]�බ�K�_�W��h�A���F�D�H�I" :),
            (: command, "say ������i�H�u���U�v�ڪ��I" :),
        }));
        return;
    }
    if( arg == "���U" ) {
        if( this_player()->query_temp("quest/tonlight") == 2) {
            do_chat(({
                (: command, "say �A�w�g�b���ڤF�I" :),
            }));
            return;
        } else
        if( this_player()->query_temp("quest/tonlight") == 1) {
            this_player()->add_temp("quest/tonlight", 1);
            do_chat(({
                (: command, "say ���N�浹�A�F�C" :),
                (: command, "say ���ڳq���Q���OŢ�N�n�C" :),
            }));
            return;
        } else {
            do_chat(({
                (: command, "?" :),
                (: command, "say ����ťť���ȬOԣ�H" :),
            }));
            return;
        }
    }
    if( arg == "����" || arg == "����" )  {
        if( this_player()->query_temp("quest/tonlight") < 1) {
            do_chat(({
                (: command, "?" :),
                (: command, "say �A�S�����U�ڧa�C" :),
            }));
        } else {
        this_player()->delete_temp("quest/tonlight");
            do_chat(({
                (: command, "hmm" :),
                (: command, "say �n�a�A�ڭ̦ۤv��I�e�̡C" :),
            }));
            return;
        }
    }
}
int give_check(object ob)
{
    if( ob->id("_TONBELI_A_") ) return 1;   // �q���Q�OŢ
    else return 0;
}
int accept_object(object me, object ob)
{
    int amount;
    object item;

    amount = ob->query_amount();

    if( is_busy() ) {
        do_chat((: command, "say �y���@�U�C" :));
        return 0;
    }
    if( is_fighting() ) {
        do_chat((: command, "say �n�å�I�����a�I" :));
        return 0;
    }
    me->start_busy(1);
    this_object()->start_busy(1);
    switch( give_check(ob) ) {
        case 1:
            if( me->query_temp("quest/tonlight") != 2) {
                do_chat((: command, "say �ڨS��A�����a�I" :));
                return 0;
            }
            amount = ob->query_amount();
            message_vision("$N���L$n���I�I�Y�C\n"NOR, this_object(), ob);
            do_chat( ({
               (: command, "say �N�O�o�ӨS���C" :),
               (: command, "say �A�������ȤF�I" :),
               ( : destruct , ob : ),
            }) );
            tell_object(me, "( "HIY+amount*50000+HIG" ��Ȥl�w�g�۰ʦs�b�Ȧ�̡C"NOR")\n");

            me->add("bank", amount*50000);

            // �����Ȧs�����
            me->delete_temp("quest/tonlight");
            break;
        default:
            do_chat((: command, "say �O����L���F�赹�ڡC" :));
            return 0;
            break;
    }
    return 1;
}
void die()
{
    object ob, *obs;
    obs = all_inventory(this_object());
    if( this_object()->query_temp("quest/psychical") == 1 ) {
        message_vision("�]��$N�����ҥH"HIW"�ᰩ�C"NOR"�������ƤF...�C\n"NOR, this_object());
        this_object()->delete_temp("quest/psychical");
        foreach( ob in obs ) destruct(ob);
    }
    ::die();
}
