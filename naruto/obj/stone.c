#include <ansi.h>

inherit ITEM;

void create()
{
    set_name(HIG"�C"HIY"�m"HIW"��"NOR, ({ "color stone", "stone", "color" }));
    set_weight(100000);

    set("unit", "��");
    set("value", 0);
    set("no_sac", 1);
    set("no_get", 1);

    set("long",
        "�]���@�ɬO���_�a�A�ܾE�A�Ҥw���Ǩƪ��w�g���_�s�b�C\n"
        "�b�o�ӥ@�ɤW�ɱ`�X�{�s���F��A�p�G�A�O�򤣤W�ɥN���H�A\n"
        "�A�K�i�H�N�@�N(touch)�o���C�m�ۡA���|��U�A�A���A�]��\n"
        "���Q���b�o�ӥ@�ɤ��~��Ȧ�C\n" 
    );
    setup();
}

void init()
{
    add_action("do_touch", "touch");
}

void clear_skill(object me)
{
    int point;

    if( me->query_skill("magic") ) {
        point = me->query_skill_ability("magic");
        me->delete_skill("magic");
        me->add_point("skill", point);
        me->save();
        tell_object(me, "�C�m�����A�����F�ޯ� �۳N(magic) �ðh�٤F " + point + " �I���ޯ��I�C\n");
    }
}

void clear_vendetta(object me)
{
    if( me->query("vendetta/0") ) {
        me->delete("vendetta/0");
        me->save();
        tell_object(me, "�C�m�����A�����F���H�N����bug�F�C\n");
    }
}

void add_camp(object me)
{
    if( me->query("guild") == "muye" && me->getCamp("muye") != 1 ) {
        me->addCamp("muye");
    } else if( me->query("guild") == "hunter" && me->getCamp("hunter") != 1 ) {
        me->addCamp("hunter");
    } else if( (me->query_class() == "little_sea" || me->query_class() == "thief_sea" ) && me->getCamp("robber") != 1 ) {
        me->addCamp("robber");
    } else if( (me->query_class() == "work_sea" || me->query_class() == "soldier_sea" ) && me->getCamp("police") != 1 ) {
        me->addCamp("police");
    } else tell_object(me, "�A��¾�~���G�S�Q�w�q��A�Ч�Ův�B�z�C\n");
}


void reset_dog(object me)
{
    int lv;
    object pet;
    pet = me->query_temp("pet");

    if( !pet || !objectp(pet) ) return;
    if( !me->query("pet") ) return;

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
    pet->set_attr("str", lv*150/100);
    pet->set_attr("con", lv*150/100);
    pet->set_attr("dex", lv*150/100);
    pet->set_attr("int", lv*150/100);
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
    pet->save();

    // ���ݭn�F
    me->delete("pet");

    tell_object(me, "�C�m�����A�B�z�F�Ԥ��s�ɰ��D�I\n");
}

int do_touch(string arg)
{
    object me = this_player();

    if( !arg || arg != "stone" )
        return notify_fail("�A�n�N����H\n");
    
    message_vision(HIW"$N�`���ڴڪ����N��$n�A�L���L�L���W���C\n"NOR, me, this_object());

    // 2007.03.16 ���� �ޯ�۳N(magic)
    clear_skill(me);

    // 2007.03.17 �������H�N��bug
    clear_vendetta(me);

    // 2007.08.18 �W�[�ª��a��¾�~�}��
    add_camp(me);

    // 2009.03.24 �Ԥ��אּ�|�s��
    reset_dog(me);

    return 1;
}
