/* animal_taming.c �ԳN�G���~���N */

#include <ansi.h>
#define SKILL_NAME   "animal taming"
#define SKILL_NAME_C "���~���N"
#define SKILL_CLASS  "ninja"
#define PET_FILE_PATH "/daemon/skill/naruto/ninja/obj/pet.c"

inherit SKILL;

void create()
{
seteuid(getuid());
    DAEMON_D->register_skill_daemon(SKILL_NAME);
}

string query_class() { return SKILL_CLASS; }

void skill_advanced(object me, string skill)
{
    int lv = me->query_skill(skill, 1);
    switch( lv ) {
    case 189: me->set_skill_require(skill, 1500000); break; // ���d3 : 189��190
    case 149: me->set_skill_require(skill, 1000000); break; // ���d2 : 149��150
    case  99: me->set_skill_require(skill, 500000);  break; // ���d1 :  99��100
    default:  me->set_skill_require(skill, lv*lv*5); break;
    }
}

// ��l���d��
void setup_dog(object me, object pet)
{
/*
    int lv;
   
    // �]�w�W�r
    if( me->query("pet/name") ) pet->set("name", me->query("pet/name"));
    
    // �]�wID
    pet->set("id", me->query_id() + "'s dog");
    
    // �]�wtitle
    if( me->query("pet/title") ) pet->set("title", me->query("pet/title"));
    
    // �]�wnickname
    if( me->query("pet/nickname") ) pet->set("nickname", me->query("pet/nickname"));

    // �]�wlong
    if( me->query("pet/long") ) pet->set("long", me->query("pet/long"));
    
    // �]�wfood
    if( me->query("pet/food") ) pet->food_gain(me->query("pet/food"));
    
    // �]�wLevel
    if( me->query("pet/level") ) pet->set_level(me->query("pet/level"));
    
    // �]�wexp
    if( me->query("pet/exp") )
        pet->exp_gain(me->query("pet/exp"));

    lv = pet->query_level();
    
    // �̵��Ŵ��ɯ�O
    pet->set_attr("str", lv*2);
    pet->set_attr("con", lv*2);
    pet->set_attr("dex", lv*2);
    pet->set_attr("int", lv*2);
    pet->set_stat_maximum("ap", lv*50);
    pet->set_stat_maximum("hp", lv*50);
    pet->set_stat_maximum("mp", lv*50);
    pet->set_stat_current("ap", lv*50);
    pet->set_stat_current("hp", lv*50);
    pet->set_stat_current("mp", lv*50);
    pet->set_skill("combat", lv*3);
    pet->set_skill("parry", lv*3);
    pet->set_skill("dodge", lv*3);
    pet->set_skill("heavy hit", lv*3);
    pet->set_skill("savage hit", lv*3);
    pet->set_skill("continual hit", lv*3);
    
    pet->do_heal();

    // �]�w�d���ثe���A
    // �u����D�H���W�O�d���Ȥp���d���̤j�Ȥ~�|�~�ӡA�קK�}��
    if( me->query("pet/ap") < pet->query_stat_maximum("ap") ) pet->set_stat_current("ap", me->query("pet/ap"));
    if( me->query("pet/hp") < pet->query_stat_maximum("hp") ) pet->set_stat_current("hp", me->query("pet/hp"));
    if( me->query("pet/mp") < pet->query_stat_maximum("mp") ) pet->set_stat_current("mp", me->query("pet/mp"));
*/
}

// �s�X�Ԥ��禡
void call_dog(object me)
{
    object pet;

    if( objectp( pet = me->query_temp("pet") ) ) {
        write("�A���Ԥ��w�g�Q�A�s�X�ӤF...\n");
        return;
    }
    
    if( me->query_skill("animal taming", 1) <= 40 ) {
        write("�A�����~�N���ݤj��40�Ť~��ϥγo�ӫ��O�C\n");
        return;
    }

    // �֦��̮����@�Ǭd�J��
    if( me->query_stat("mp") < 20 ) {
        write("�A�ثe�S���������d�J�ԨӨϥι��~�N�C\n");
        return;
    }

    pet = new(PET_FILE_PATH);
    if( !objectp(pet) ) {
        write("�A���G�S��k�I�s�A���Ԥ��X��...\n");
        destruct(pet);
        return;
    }

    message_vision(HIW"$N�q���˸̱ǥX�@���l�j�F�X�U�A�y�W�S�X���������e...\n"NOR, me);

    // ��l���d�����A
    // setup_dog(me, pet);
    // �אּ�s�ɤ覡�A��l�ƧY�����^�s��
    // restore�e�᳣�n�]owner, �]��restore��owner�|����
    pet->set_owner(me);      //�]�wowner
    pet->restore();
    pet->restore_autoload();
    pet->set_owner(me);      //�]�wowner
    pet->reset_action();     //���s�]�w�ʧ@, �]restore��|����

    if( environment(me)->is_area() ) {
        if( !area_move(environment(me), pet, me->query("area_info/x_axis"), me->query("area_info/y_axis")) ) {
            write("�A���Ԥ��X�ӫ�A�S�@�ȷϦa�]���F...\n");
            destruct(pet);
            return;
        }
    } else {
        if( !pet->move(environment(me)) ) {
            write("�A���Ԥ��X�ӫ�A�S�@�ȷϦa�]���F...\n");
            destruct(pet);
            return;
        }
    }

    if( me->query_skill("animal taming", 1) > 50 ) pet->set_leader(me);     //���Hleader

    me->set_temp("pet", pet);
    
    message_vision("$n�@����$N�����o���Ӹ��h�u�L�I�L�I�v�s...\n", me, pet);

    me->damage_stat("mp", 20, me);
    me->start_busy(3);

    // �W�[�ޯ�g��
    me->improve_skill("animal taming", 1);
    me->improve_skill("ninja", 1);

    if( me->query_skill("animal taming", 1) > 60 ) pet->guard_ob(me);       //�O�@leader
    
    return;
}

// �R���d���禡
void destruct_dog(object me)
{
//    mapping petr=([]);
    object pet;
    
    if( !objectp(pet = me->query_temp("pet")) ) {
        write("�A�ثe�S���s�X�A���Ԥ��X��...\n");
        return;
    }
    
    if( pet->is_fighting() || pet->is_busy() ) {
        write("�A���Ԥ����G�b���Ǥ���A�@�ɲ椣�F��...\n");
        return;
    }
    
    // �d�����A�x�s
    /* �אּ�s�ɤ覡�A���ݭn���^���A
    petr["name"] = pet->query("name");
    petr["title"] = pet->query("title");
    petr["nickname"] = pet->query("nickname");
    petr["long"] = pet->query("long");
    petr["exp"] = pet->query_exp();
    petr["food"] = pet->query_food();
    petr["level"] = pet->query_level();
    petr["ap"] = pet->query_stat("ap");
    petr["hp"] = pet->query_stat("hp");
    petr["mp"] = pet->query_stat("mp");    
    me->set("pet", petr);
    */
    pet->save_autoload();
    pet->save();
    pet->do_destruct();
    me->delete_temp("pet");
    
    write("�A���Ԥ����}�F�C\n");
    
    return;
}

string status_color(int current, int max)
{
    int ratio = max ? (current * 100) / max : 100;

    switch( ratio ) {
        case  0..25: return HIR;
        case 26..50: return HIM;
        case 51..75: return HIY;
        case 76..100: return HIG;
        default: return HIC;
    }
}

void show_state(object me)
{
    object pet;
    string msg;
    
    if( !objectp(pet = me->query_temp("pet")) ) {
        write("�Х��s�X�A���Ԥ��C\n");
        return;
    }

    if( me->query_skill("animal taming", 1) <= 20 ) {
        write("�A�����~�N���ݤj��20�Ť~��ϥγo�ӫ��O�C\n");
        return;
    }

    printf("[%s] ���� %d  �g��� %2.2f%s  �����q %s%d/%d\n"NOR,
        pet->query("name"),
        pet->query("level"),
        (pet->query_exp()*10.0 / (pet->query("level") * pet->query("level"))),
        "%",
        status_color(pet->query_food(), pet->query_food_maximum()),
        pet->query_food(),
        pet->query_food_maximum() );

    return;
}


void feed_dog(object me, string item)
{
    int stuff, heal;
    object food, pet;
    
    if( !objectp(pet = me->query_temp("pet")) ) {
        write("�Х��s�X�A���Ԥ��C\n");
        return;
    }
    
    if( me->query_skill("animal taming", 1) <= 30 ) {
        write("�A�����~�N���ݤj��20�Ť~��ϥγo�ӫ��O�C\n");
        return;
    }

    food = present(item, me);
    if( !food ) food = present(item, environment(me));
    if( !food ) {
        write("�o�̨S���o�˪F�� ...\n");
        return;
    }

    stuff = food->query("food_stuff");

    if( !stuff ) {
        write("�o�˪F����G����Y...\n");
        return;
    }
    
    // �W�[�����q
    if( !pet->food_gain(stuff) ) {
        write("�A���Ԥ��w�g�Y���U����F��F...\n");
        return;
    }

    if( !food->stuff_ob(pet)) {
        write("�o�˪F����G����Y...\n");
        return;
    }

    message_vision("$N�Y�U�F�@" + ( food->query("base_unit") ? food->query("base_unit") : food->query("unit") ) + "$n�C\n", pet, food);
    
    food->add_amount(-1);
    if( food->query_amount() <= 0 ) destruct(food);

    // �Y�F��|�W�[�g���
    pet->exp_gain(stuff);
    
    return;
}

void set_data(object me, string key, string value)
{
    object pet;
    
    if( !objectp(pet = me->query_temp("pet")) ) {
        write("�Х��s�X�A���Ԥ��C\n");
        return;
    }
    
    if( me->query_skill("animal taming", 1) <= 100 ) {
        write("�A�����~�N���ݤj��100�Ť~��ϥγo�ӫ��O�C\n");
        return;
    }

    if( key == "name" ) {
        if( strlen(value) > 10 ) {
            write("�A�u�ର�A���Ԥ������Ӥ���r�j�p�H�����W�r�C\n");
            return;
        }
        write("�A���A���Ԥ����W�� " +value + "�C\n");
        pet->set("name", value);
        return;
    }
    
    if( key == "title" ) {
        if( strlen(value) > 14 ) {
            write("�A�u�ର�A���Ԥ����C�Ӥ���r�j�p�H�����Y�ΡC\n");
            return;
        }
        write("�A���A���Ԥ����Y�Ψ��� " +value + "�C\n");
        pet->set("title", value);
        return;
    }

    if( key == "nickname") {
        if( strlen(value) > 14 ) {
            write("�A�u�ର�A���Ԥ����C�Ӥ���r�j�p�H�����~���C\n");
            return;
        }
        write("�A���A���Ԥ����~������ " +value + "�C\n");
        pet->set("nickname", value);
        return;
    }
    
    if( key == "long") {
        if( strlen(value) > 200 ) {
            write("�A�u�ର�A���Ԥ��]�w�@�ʭӤ���r�j�p�H�����y�z�C\n");
            return;
        }
        write("�A���A���Ԥ����y�z�]�� " +value + "�C\n");
        pet->set("long", value);
        return;
    }

    write("�A�ثe����Ԥ�����T�� name, title, nickname, long ...\n");
    return;
}

// �ϥε���
int perform_action(object me, string act, object target)
{
    string k, v;
    if( !objectp(me) ) return 0;
    if( me->is_busy() ) return notify_fail("�A�{�b�S���Ũϥι��~���N�C\n");

    if( me->query_skill("ninja", 1) < 20 ) return notify_fail("�A����O�����H�ϥγo�ӧޯ�C\n");

    switch( act ) {
        case     "call": call_dog(me); break;
        case    "leave": destruct_dog(me); break;
        case    "state": show_state(me); break;
        default:
            if( sscanf(act, "feed %s", k) == 1 ) {
                feed_dog(me, k);
            } else if( sscanf(act, "set %s %s", k, v) == 2 ) {
                set_data(me, k, v);
            } else return notify_fail("�ثe���~���N�� feed, call, leave, state, set ���إ\\��C\n"); break;
        break;
    }
    
    return 1;
}
