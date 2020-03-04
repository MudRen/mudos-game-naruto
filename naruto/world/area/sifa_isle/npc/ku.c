#include <npc.h>
#include <ansi.h>

inherit F_SOLDIER;
inherit F_TRAINER;    // �V�m�ɮv

void do_fight()
{
    string area_file = "/world/area/sifa_isle/aineaisi.c";
    object enemy, area;
    object* targets;
    int i, damage, raiseDamage, exact, evade;

    // �S���ĤH
    enemy = this_object()->query_opponent();
    targets = this_object()->query_enemy();
    i = random(3) + 1;

    if( !enemy ) return;

    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    // �����G��-���V�����A�A�w�g�ιL�~�Χޯ�
    if( !query("fruit_horse", 1) ) {
        message_vision(CYN"\n$N�ϥΰʪ��t�y"HIY"�����G��"NOR"�w"BLINK+YEL"���V�����A"NOR+CYN"�z���ĪG�A�ܤƬ����V���F�I\n"NOR, this_object());

        set_skill("sock power", 50);           // �s�ޯ�A�M���ΨӴ����P�R���v�Amob�M��
        set_skill("sock bom", 25);             // �s�ޯ�A�M���ΨӴ����P�R�ˮ`�Amob�M��
        set_skill("paper step", 200);          // �W�[��ø�o�ʲv
        add_temp("apply/intimidate", 150);     // ������O
        add_temp("apply/wittiness", 200);      // ���m��O
        add_temp("apply/evade", 100);          // �j��
        add_temp("apply/exact", 150);          // �R��
        set("name", "�d�w"YEL"[���V��]"NOR);   // �W�r�ץ�

        message_vision("$N���D�G"HIG"�ڴN�O���w���V���I$n"HIG"���N���ܡI\n"NOR, this_object(), enemy);
        set("fruit_horse", 1);
        return;
    }
    // �����h�H�����γ�H����
    if( sizeof(targets) >= 2 ) {
        switch( i ) {
            case 1: // �P�}�E����
                if( query("fruit_horse", 1) ) {
                    exact = COMBAT_D->evade(this_object(), enemy, 1)*1.1;

                    add_temp("apply/exact", exact);
                    message_vision("\n$N���D�R"HIG"�s�Ѿ����\n"NOR, this_object());
                    message_vision("$N"HIC"�N��l�Y�_������}�ϥX"HIB"�u�P�}�E����v"HIC"�µۥ|���K��g�X���𫬪������I\n"NOR, this_object(), enemy);
                    for(i=0;i<sizeof(targets);i++) {
                        if( !COMBAT_D->isHit(this_object(), targets[i]) ) {
                            message_vision(HIW"$N"HIW"��Ĩ��m���A�A�N���Ӫ��������������A�S�����ˡC\n"NOR, targets[i]);
                        } else {
                            raiseDamage = 800;
                            add_temp("apply/attack", raiseDamage); 
                            damage = COMBAT_D->isDamage(this_object(), targets[i], 0);
                            add_temp("apply/attack", -raiseDamage);
                            targets[i]->receive_damage(damage, this_object());
                            message_vision( sprintf(HIR"�U�Q����������������L$n"HIR"�����l�A��$n"HIR"�y�夣��(%d) %s\n", damage, COMBAT_D->report_status(targets[i]) ), this_object(), targets[i]);
                        }
                    }
                    add_temp("apply/exact", -exact);
                    message_vision("\n"NOR, this_object());
                    break;
                }
            case 2: // �Q��}�B
                if( query("fruit_horse", 1) ) {
                    exact = COMBAT_D->evade(this_object(), enemy, 1)*1.4;

                    message_vision("\n$N���D�R"HIG"�����|���A���L�����C\n"NOR, this_object());
                    message_vision("$N"HIK"�N"NOR+YEL"���V��"HIK"�������Y���|��ΡA�åB�ªŤ��g�X�j�q����"HIW"�u�P�}�v"HIR"\n��$n"HIR"�ٷd���M��"NOR"$N"HIR"�����ϮɡA������������ϼu�g�V$n"HIR"���H�A���p�U�B�몺"HIB+BLINK"�y�Q��}�B�z"NOR+HIR"�I\n\n"NOR, this_object(), enemy);
                    for(i=0;i<sizeof(targets);i++) {
                        if( targets[i]->is_busy() ) continue;
                        evade = COMBAT_D->evade(targets[i], this_object(), 1);

                        if( !COMBAT_D->SkillHit(this_object(), targets[i], exact, evade) ) {
                            message_vision(HIW"$N"HIW"�u�n���Ȯɩ������A�����}�B�������d��C\n"NOR, targets[i]);
                        } else {
                            raiseDamage = 500;
                            add_temp("apply/attack", raiseDamage); 
                            damage = COMBAT_D->isDamage(this_object(), targets[i], 0);
                            add_temp("apply/attack", -raiseDamage);
                            targets[i]->receive_damage(damage, this_object());
                            targets[i]->start_busy(2);
                            message_vision( sprintf(HIB"�B�몺�������_�q�Ѧӭ�����$n"HIB"�A�ڥ��L�i���m(%d) %s\n", damage, COMBAT_D->report_status(targets[i]) ), this_object(), targets[i]);
                        }
                    }
                    message_vision("\n"NOR, this_object());
                    break;
                }
            case 3: // �P�}�E��
                command("say ���a�H�h�O����Ĺ�Ѧ����I" );
                command("perform kick luan.kick on " + enemy->query_id() );
                break;
        }
        return;
    }
    switch( i ) {
        case 1: // �Q��U�g�r
            if( query("fruit_horse", 1) ) {
                exact = COMBAT_D->exact(this_object(), enemy, 1)*1.2;
                evade = COMBAT_D->evade(enemy, this_object(), 1);

                message_vision("\n$N"HIY"�Y�_�Y���A�N�ؼй�ǤF$n"HIY"�I"NOR+YEL+BLINK"�y�Q�ﯥ�x�z"NOR+HIY"�W�իݵo�ǳƧ����I\n"NOR, this_object(), enemy);
                if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
                    message_vision(HIK"$N"HIK"�t�D�����A�������C���l�׶}"HIW"�u�Q��U�g�r�v"HIK"�b��W�F�X�@�Ӥ諬�j�}�I\n\n"NOR, enemy);
                    start_busy(2);
                } else {
                    raiseDamage = 3000;
                    add_temp("apply/attack", raiseDamage); 
                    damage = COMBAT_D->isDamage(this_object(), enemy, 0);
                    add_temp("apply/attack", -raiseDamage);
                    enemy->receive_damage(damage, this_object());
                    message_vision( sprintf(HIR"��$n"HIR"�ǳư{���ɡA"NOR"$N"HIR"�o��"HIW"�u�Q��U�g�r�v"HIR"�r�O����$n"HIR"�I$n"HIR"�e��@�n�Q�����X�h�I(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
                    start_busy(1);
                    if( !objectp(area = load_object(area_file)) ) return;
                    if( !area->is_area() ) return;
                    if( !area_move(area, enemy, random(28)+1, random(28)+11) ) return;
                    message_vision(CYN"����u�F���v�@�n���T�A�������˪�$N"CYN"�q�̭��L�F�X�ӡC\n\n"NOR, enemy);
                }
                return;
                break;
            }
        case 2: // �P�}�E�s�_
            exact = COMBAT_D->exact(this_object(), enemy, 1)*1.5;
            evade = COMBAT_D->evade(enemy, this_object(), 1);

            if( !enemy->is_busy() ) {
                raiseDamage = 1500;
                command("say �n���n���K���ө�סA�O�ѧڪ������ӨM�w�C" );
                message_vision("$N"HIK"�@���N�ݬ�F"NOR"$n"HIK"���U�Ӫ���ʡA�@��"NOR+YEL"�y�P�}�E�s�_�z"HIK"��������"NOR"$n"HIK"�n�`�I\n"NOR, this_object(), enemy);
                if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
                    message_vision("\t$n�o�{$N�~�M���ϥ��K�����������A���W�ܩ۾פU�F�����C\n"NOR, this_object(), enemy);
                    start_busy(3);
                    enemy->start_busy(1);
                } else {
                    add_temp("apply/attack", raiseDamage); 
                    damage = COMBAT_D->isDamage(this_object(), enemy, 0);
                    add_temp("apply/attack", -raiseDamage);
                    enemy->receive_damage(damage, this_object());
                    message_vision( sprintf(HIY"�s�������r���F$n"HIY"���n�`�A$n"HIY"�G�s�@�n�A�@�ɶ��L�k���(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
                    start_busy(1);
                    enemy->start_busy(5);
                }
                return;
                break;
            }
        case 3: // �P�}�E�չp
            if( query_condition("white_cd") ) return;
            command("say �P�}�I...�չp�I" );
            command("perform kick thunder.kick on " + enemy->query_id() );
            break;
    }
    return;
}
void check_fruit()
{
    // �S�b�԰��n�^�_���H��
    if( query("fruit_horse", 1) ) {
        set("name", "�d�w");                    // �W�r�ץ�
        message_vision("$N�n�n�Y��_���H�����D�G"HIG"���Ѧ�������w�Y�סC\n"NOR, this_object());
        delete("fruit_horse");
        delete_skill("sock power");
        delete_skill("sock bom");
        set_skill("paper step", 160);           // ��֯�ø�o�ʲv
        add_temp("apply/intimidate", -150);     // ������O
        add_temp("apply/wittiness", -200);      // ���m��O
        add_temp("apply/evade", -100);          // �j��
        add_temp("apply/exact", -150);          // �R��
    }
    do_heal();
    return;
}
void create()
{
    set_name("�d�w", ({ "ka ku", "ka", "ku" }) );
    set_race("human");
    set_level(70);
    set_class("guard_sea");         // ���x�ս�
    set("classify", "strengthen");  // �j��
    set("age", 25);
    set("title", HIR"�Ѣޢ�"NOR);
    set("long", "��l������西�����k�H�A����@��ݰ_�ӫܦѦ����B�ʪA�A���~\n"
                "�����Ӥ��|�Ӥj�C�u���L���b�Ф����G�b���ݵۤ���Ʊ�����ӡC��\n"
                "�۲����n���b��Ҥ���C\n"
                "����M���x�ޯ�i���۾ǲߡA�Q�� train ���O�ӦV�d�w�ǲߧޯ�C\n"
                "�ϥ� list ���O�d�ߥi�ǲߪ��ޯ�C��C\n" );

    set("chat_chance", 20);
    set("chat_msg", ({
        (: check_fruit :),
    }) );
    set("chat_chance_combat", 35);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    // �ܩ��h���x�٬O����èS���v�T
    set("guild", "piece");

    // �]�w��V�m���ޯ�
    //
    // set_train(�ޯ�W, �O�_�i�����߱o, �ǲ߸ӧޯ�һݭn�����ⵥ��, ���ޯ�i�ǲߨ쪺�W������)
    //
    // ���a�S���ӧޯ�ɡA�Y"�O�_�i�����߱o"�o�ӳ]�w�Ȭ��D�s�ȮɡA���a�V�V�m�̾ǲ߮ɫh�i�O��
    // �o�ӧޯ��lv1�A�Ӧ�lv���ޯ�~�i�H���I�~����m�C�G�i�Ω�S��ޡA�n�����o��lv���i�V�m�C
    //
    set_train_with_camp("combat", 1, 1, 200, "police", -2);             // �氫�ޥ�
    set_train_with_camp("dodge", 1, 1, 180, "police", -2);              // �{���ޥ�
    set_train_with_camp("parry", 1, 1, 180, "police", -2);              // �׮�ޥ�
    set_train_with_camp("heavy hit", 1, 5, 140, "police", -2);          // �������N
    set_train_with_camp("savage hit", 1, 5, 160, "police", -2);         // �������N
    set_train_with_camp("continual hit", 1, 5, 200, "police", -2);      // �s�����N
    set_train_with_camp("spurn", 1, 10, 200, "police", -2);             // ��ް�¦
    set_train_with_camp("kick haze", 1, 15, 180, "police", 1);          // ��ޡG�P�}
    set_train_with_camp("kick thunder", 0, 40, 80, "police", 2);       // ��ޡG�P�}�E�չp
    set_train_with_camp("kick luan", 0, 30, 120, "police", 1);          // ��ޡG�P�}�E��

    set("set_drop", ({
        ([ "type":"obj", "id":28, "amount":10+random(31), "p1":100, "p2":100 ]),   // ����
        ([ "type":"eq", "id":8, "amount":1, "p1":80, "p2":100 ]),                  // �Ǧ�l��
    }) );
    setup();
    set_skill("combat", 200);
    set_skill("dodge", 200);
    set_skill("parry", 200);
    set_skill("heavy hit", 150);
    set_skill("savage hit", 160);
    set_skill("continual hit", 200);
    set_skill("spurn", 200);
    set_skill("body iron", 180);
    set_skill("paper step", 160);
    set_skill("kick haze", 200);
    set_skill("kick thunder", 200);
    set_skill("kick luan", 200);

    add_temp("apply/exact", 150);       // �R��
    add_temp("apply/evade", 100);       // �j��
    add_temp("apply/intimidate", 150);  // ������O
    add_temp("apply/wittiness", 100);   // ���m��O
    add_temp("apply/str", 15);
    add_temp("apply/dex", 25);

    carry_object(__DIR__"eq/pants.c")->wear();
    carry_object(__DIR__"eq/suit.c")->wear();
}
void die()
{
    object enemy, killer;
    int i;
    string msg;

    enemy = this_object()->last_damage_giver();
    i = 85 + random(16);

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
    msg = "\n\n"+this_object()->query("name")+HIY"���b�a�W���ۡG�ڿ�F�I�H��Ӧ�h��q�O...\n\n"+enemy->query("name")+"�H�f�^�D�G�A�٦��ʪ����...\n\n"NOR+this_object()->query("name")+HIY"�H�Y�j���ۻ��G������..."+enemy->query("name")+"�o�ӤH�ٯu�����...\n\n"NOR;
    msg += HIB"�i�@�ɬF���j�Ѣޢ��u�����v����"+this_object()->query("name")+HIB"("+this_object()->query("id")+")�~�M�Q"+enemy->query("name")+"("+enemy->query("id")+")���ѤF�I\n\n"NOR;

    killer->add("exchange", i);
    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    tell_object(killer, HIY"(�]���A�����d�w��o�F "+i+" �I�I���I�ơC)\n"NOR);
    ::die();
    return;
}
