#include <npc.h>
#include <ansi.h>

inherit F_TRAINER;         // �V�m�Ѯv

void do_fight()
{
    object enemy;
    int i, j, damage, raiseDamage, exact, evade;

    // �S���ĤH
    enemy = this_object()->query_opponent();

    if( !enemy ) return;

    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    if( !query_condition("dp") ) {
        command("perform double physique.dp");
        return;
    }
    switch( random(2) ) {
        case 0:  // �׼u�Ԩ�
            command("perform muscle tank.attack on " + enemy->query_id() );
            break;
        case 1:  // �w��-�׼u�Ԩ�
            i = random(11) + 5;
            exact = COMBAT_D->intimidate(this_object(), 1) + query_attr("con")*3;
            evade = enemy->query_attr("con")*3;

            message_vision(CYN"\n$N�q�I����U�@��÷�l�A�H���֪����k�N"HIG+chinese_number(i)+NOR+CYN"��W�L�j�b÷�W"NOR"\n\n$N���D�G"HIG"��$n������D�a���ޡE�׼u�Ԩ����j�ƪ��I\n\n"NOR, this_object(), enemy);
            message_vision(HIW"�u��$N�N÷�l�j�b���W�A�ΥL�Τj�����߬I�i�_�F"HIK"�y�w��-"HIC"�׼u�Ԩ�"HIK"�z"HIW"��$n���h�I\n"NOR, this_object(), enemy);
            if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
                message_vision("���O$n�ֳt�a�q����{�F�}�ӡA�d�U�@�D�`�`���u������I\n\n\n"NOR, this_object(), enemy);
            } else {
                raiseDamage = 1150;

                add_temp("apply/attack", raiseDamage); 
                damage = COMBAT_D->isDamage(this_object(), enemy, 0);
                add_temp("apply/attack", -raiseDamage);

                if( damage < 500 ) damage = random(250) + 250;

                enemy->receive_damage(damage, this_object());
                message_vision( sprintf(HIR"�u�I�v�a�@�n�A�׼u�������W�F$n"HIR"�A$n"HIR"�uı�o���V�@���A�A��K�R�F�X��(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
                message_vision(CYN"���O��թ|������A�׼u�Ԩ��������ۡA÷�W�Ҹj���W�L���_�ζ�$n"CYN"�I\n"NOR, this_object(), enemy);
                for(i;i>0;i--) {
                    damage = i*20;
                    enemy->receive_damage(damage, this_object());
                    j = random(4) + 1;
                    damage += random(50);
                    message_vision(HIC""+chinese_number(i)+"��W�L���ˤF$n"HIC"�A�`�@�y���F "HIR+damage+HIC" �I�ˮ`�I"NOR, this_object(), enemy);
                    if( i < j ) {
                        j = i;
                        i = 0;
                    } else {
                        i -= j - 1;
                    }
                    message_vision(HIK"("+chinese_number(j)+"��W�L�]�����渨)\n"NOR, this_object(), enemy);
                }
                message_vision(CYN"\n�W�L���Ʋ渨�A$n�ߨ�ϫl�u���F$N�I "+COMBAT_D->report_status(enemy)+"\n\n"NOR, this_object(), enemy);
            }
            start_busy(5);
            return;
            break;
    }
    return;
}

void to_do_say()
{
    if( random(100) < 15 ) {
        do_chat( ({ 
            (: command, "say �{�l�n�j�ڡ�ڷQ�Y�@�I���@�˪��C" :),
            (: command, "say ���H��u�����v�ڧ�Y���ܡA�j�������ʡ�" :),
        }) );
    }
    do_heal();
}

void create()
{
    set_name("��D�B��" , ({ "din zhi", "zhi", "din" }) );
    set("guild", "muye");
    set_level(50);
    set("gender", "male");
    set_class("middle");            // ����
    set("classify", "strengthen");  // �j��
    set("age", 16);
    set("camp", "muye");
    set("long", "�@�Ӷ��D�D���츭���Ԫ̡A�ݰ_�Ӵ��p�ѹ�C�ݩ�������p������\n"
                "���C�u���L��̮��۹s���������Y�A�Y������ߨ�H�A�ײ��L�k����\n"
                "���t�פS���X�@�]�s���s���~��Y���Y�A���H���ز`���i�����Pı�C\n");

    set("chat_chance", 20);
    set("chat_msg", ({
        (: to_do_say :),
    }) );

    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );

    set_train_with_camp("combat", 1, 1, 140, "muye", -2);             // �氫�ޥ�
    set_train_with_camp("dodge", 1, 1, 80, "muye", -2);               // �{���ޥ�
    set_train_with_camp("parry", 1, 1, 160, "muye", -2);              // �׮�ޥ�
    set_train_with_camp("heavy hit", 1, 5, 160, "muye", -2);          // �������N
    set_train_with_camp("savage hit", 1, 5, 180, "muye", -2);         // �������N
    set_train_with_camp("continual hit", 1, 5, 80, "muye", -2);       // �s�����N
    set_train_with_camp("ninja", 1, 10, 120, "muye", -1);             // �ԳN
    set_train_with_camp("force", 1, 10, 160, "muye", -1);             // ��N
    set_train_with_camp("double physique", 1, 15, 160, "muye", -1);   // ��N�G���ƳN
    set_train_with_camp("akimichi pill", 0, 20, 120, "muye", 0);      // �ԳN�G��D����
    set_train_with_camp("muscle tank", 0, 21, 140, "muye", 0);        // ��N�G�׼u�Ԩ�

    setup();
    set_skill("combat", 150);
    set_skill("continual hit", 120);
    set_skill("heavy hit", 160);
    set_skill("savage hit", 200);
    set_skill("ninja", 140);
    set_skill("force", 200);
    set_skill("akimichi pill", 200);
    set_skill("double physique", 200);
    set_skill("muscle tank", 200);

    // ���[��O�A������O���I�t
    add_temp("apply/intimidate", 150);  // �����ޥ�
    add_temp("apply/wittiness", 200);   // ���m�ޥ�
    add_temp("apply/armor", 300);       // ���m��O
    add_temp("apply/con", 30);
}

void relay_say(object ob, string arg)
{
    if( !ob->query_skill("muscle tank") && arg == "����" && ob->query("level") >= 20 )  {
        if( ob->query("guild") != "muye" ) {
            tell_object(ob, CYN"��D�B���ݤF�A�@���A�o�{�A���O�츭�Ԫ̡A�K���n�N��·ЧA�F�C\n");
            return;
        }
        if( !ob->query_temp("muscle_tank") ) {
            ob->set_temp("muscle_tank", 1);
            do_chat( ({ 
                (: command, "say �A�Q�n�����ڷj�������ܡH" :),
                (: command, "say �ӷP�¤F�A�ڤ���Q�Y�u�ɶ���Į�j���t�Y���G���ѡv�Ať���@�֩����]����|�N�C" :),
                (: command, "say �������o�@�����ڧa�C" :),
            }) );
        } else {
            do_chat( ({ 
                (: command, "say �ڤ��O�w�g���U�A�F�ܡH" :),
                (: command, "say �ڤ���Q�Y�u�ɶ���Į�j���t�Y���G���ѡv�Ať���@�֩����]����|�N�C" :),
                (: command, "say �������o�@�����ڧa�C" :),
            }) );
        }
        return;
    }
}

int give_check(object ob)
{
    if( ob->id("_GOOD_FOOD_") ) return 1;              // �ɶ���Į�j���t�Y���G����
    else return 0;
}

int accept_object(object me, object ob)
{
    object item;

    if( is_busy() ) {
        tell_object(me, "��西�b���L���A�е��@�U�C\n");
        return 0;
    }
    if( is_fighting() ) {
        do_chat((: command, "say �O�n�I�S�ݨ�ڥ��b���[�ڡI" :));
        return 0;
    }
    me->start_busy(1);
    this_object()->start_busy(1);

    switch( give_check(ob) ) {
        case 1:
            if( !me->query_temp("muscle_tank") ) {
                do_chat((: command, "say �ڤS�S�n�A���ڪ����A�o���n�N�䦬�U..." :));
                return 0;
            }
            message_vision("$N�������S�s�S��...\n", this_object());

            if( !me->query_skill("muscle tank") ) {
                command("say ��b�O�ӷP�¤F�A�ڴN�ЧA�׼u�Ԩ����ޥ��a...\n");
                tell_object(me, HIW"(�A�Ƿ|�F�׼u�Ԩ��F�C)\n"NOR);
                me->set_skill("muscle tank", 1);
                me->delete_temp("muscle_tank");
            }
            do_chat( ({ ( : destruct , ob : ) }) );
            break;
    }
    return 1;
}

void die()
{
    object enemy, killer;
    int i = 25 + random(6);
    string msg;

    enemy = this_object()->last_damage_giver();

    if( !enemy ) {
        destruct(this_object());  // �䤣����A��������
        return;
    }
    // �d��������D�H��
    if( !userp(enemy) && objectp(enemy->query_owner()) ) {
        killer = enemy->query_owner();
    } else {
        killer = enemy;
    }
    msg = "\n"+this_object()->query("name")+"������y���D�G"HIG"�ڵL�k�~�Ӭ�D�a���W���F�I\n\n"HIY"����...���Y...�ڶd�t�F�A�̪�����...\n\n"NOR;
    msg += HIG"�i"HIR"�츭�ְT"HIG"�j"HIG"��"HIM"�u�ޡB���B���v"HIG"���٪���D�a�Ԫ�"+this_object()->query("name")+"�A�G����"+enemy->query("name")+"����C\n\n\n"NOR;

    killer->add("exchange", i);
    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    tell_object(killer, HIY"(�]���A����"+this_object()->query("name")+"��o�F "+i+" �I�I���I�ơC)\n"NOR);
    ::die();
    return;
}

int accept_kill(object me, string arg)
{
    if( query_condition("dp") == 0) {
        message_vision("$N���D�R"HIG"�Q�m�ڪ������ܡI�I�O�Q�k�I\n"NOR, this_object());
        command("perform double physique.dp");
    } else {
        message_vision("$N���D�R"HIG"�����p���I\n"NOR, this_object());
    }
}
