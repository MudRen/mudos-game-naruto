int num;

void do_fight()
{
    mapping cnd = ([]);
    int damage, raiseDamage, i, exact, evade;
    object enemy;
    object* targets;

    enemy = this_object()->query_opponent();
    targets = this_player()->query_enemy();

    if( !enemy ) return;
    if( this_object()->is_busy() ) return;

    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    switch( query("skill_list") ) {
        case 0: // �Z�Юa-���L���s
            if( random(2) == 1 ) {
                command("perform takeda lance.lunge");
            } else {
                if( this_object()->query_condition("fourskills") != 0 ) break;
                this_object()->damage_stat("mp", 5, this_object());
                message_vision("\n$N���R��"+query("name")+"�ϥX�Z�Юa���ǧޥ��u"HIC"��"HIG"�L"HIR"��"HIY"�s"NOR"�v�P�j�۵M�P�ơA�@�s�@�͡I\n\n", this_object(), enemy);

                cnd["name"] = HIC"��"HIG"�L"HIR"��"HIY"�s"NOR;
                cnd["duration"] = 60;

                this_object()->set_condition("fourskills", cnd);
            }
            break;
        case 1: // �d��-�������s��
            if( random(2) == 1 ) {
                command("perform wu fire finger.fire");
            } else {
                add_temp("apply/attack", 100);
                this_object()->damage_stat("mp", 5, this_object());
                message_vision("\n$N�ɳܤ@�n�u"HIR"������"NOR"�ĶL�B�m���w"RED"���s"NOR"�v�P�ɥk�ⴤ���¦a���@���I\n\n"NOR, this_object(), enemy);
                for(i=1;i<4;i++) {
                 message_vision(CYN"���s�z�o ��"+chinese_number(i)+"��\n"NOR, this_object(), enemy);
                    COMBAT_D->fight(this_object(), enemy, this_object()->query_temp("weapon/twohanded"));
                }
                add_temp("apply/attack", -100);
                message_vision("\n$N"CYN"���^�F��"NOR"$n"CYN"�������������I\n\n"NOR, this_object(), enemy);
                this_object()->start_busy(5);
            }
            break;
        case 2: // �Q��-�B��C
            if( random(2) == 1 ) {
                command("perform wei ice sword.ice");
            } else {
                if( enemy->is_busy() ) return;
                exact = COMBAT_D->intimidate(this_object(), 1)*1.2;
                evade = COMBAT_D->wittiness(enemy, 1);

                this_object()->damage_stat("mp", 5, this_object());
                message_vision("\n$N�H�u�Q��"HIC"���B�C"NOR"�v�A�_�C�R�A�@�ɶ�����ɭ��٬O�n�ݡC\n"NOR, this_object(), enemy);
                if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
                    message_vision("���L$N�ߧY�^�L���ӡA�S���Q�o�}����Ҽv�T�C\n\n", enemy, this_object());
                    this_object()->start_busy(2);
                } else {
                    message_vision("$N�n���ݧb�F�A�S���Q�o����ҧN��A��ӤH�b�h��F�I\n\n", enemy, this_object());
                    enemy->start_busy(5);
                }
            }
            break;
        case 3: // ��Q�a-�s���`�r
            if( random(2) == 1 ) {
                command("perform mouri bow.loose");
            } else {
                this_object()->damage_stat("mp", 5, this_object());
                message_vision("\n$N�ϥγy��ޥ��u"HIW"�s��"NOR"�v�P�u"HIK"�`�r"NOR"�v���ۤv�W�[���m��O�C\n"NOR, this_object(), enemy);
                if( random(this_object()->query_level()) < 10 ) {
                    this_object()->add_temp("apply/armor", -num);
                    num = 0;
                    message_vision("���G$N���s�@��q�ӹL���W�A�����W�[�����m���Y���F�I\n\n", this_object(), enemy);
                    this_object()->start_busy(2);
                } else {
                    damage = random(this_object()->query_level());
                    if( num <= 0 ) num = damage;
                    else num += damage;
                    message_vision("�g�L�F$N���ɱj�A��$N�ۨ������m�����F�\�h�I\n\n", this_object(), enemy);
                    this_object()->add_temp("apply/armor", damage);
                }
            }
            break;
        case 4: // �W��-�V�ᤧ�s
            if( random(2) == 1 ) {
                command("perform nagao katana.hew");
            } else {
                exact = COMBAT_D->exact(this_object(), enemy, 1)*1.1;
                evade = COMBAT_D->evade(enemy, this_object(), 1);

                this_object()->damage_stat("mp", 15, this_object());
                message_vision("\n$N�Q�����ߤO�s�����o�ʧ����u"HIW"�V���s�k"NOR"�E"HIC"����"NOR"�v���p�s�������V$n�I\n"NOR, this_object(), enemy);
                if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
                    message_vision("�֪�$n���N���}�F�����d��A$N�ۤv�઺�Y�w�دt�I\n\n", this_object(), enemy);
                    this_object()->start_busy(6);
                } else {
                    raiseDamage = 700;

                    add_temp("apply/attack", raiseDamage); 
                    damage = COMBAT_D->isDamage(this_object(), enemy, query_temp("wield/righthand"));
                    add_temp("apply/attack", -raiseDamage);

                    if( damage < 200 ) damage = 150 + random(50);

                    enemy->receive_damage(damage, this_object());
                    if( damage >= 600 ) {
                        message_vision( sprintf("$n�����Q�ۭ��Ұg�b�A���������Y���A�s��V���d���M���F(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
                        enemy->start_busy(3);
                    } else {
                        message_vision( sprintf("$n�Q���J�ۭ����A�Q�U�Q���Z�h�M�媺��L����(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
                    }
                    this_object()->start_busy(2);
                }
            }
            break;
        case 5: // ´��-�K���X��
            if( random(2) == 1 ) {
                switch( random(3) + 1) {
                    case 1: command("perform germ gun.loose");
                    case 2: command("perform germ gun.loose");
                    case 3: command("perform germ gun.loose"); break;
                }
            } else {
                exact = COMBAT_D->intimidate(this_object(), 1)*1.8;

                this_object()->damage_stat("mp", 5, this_object());
                message_vision("\n$N�N�ؤl�q"REV"�K��"NOR"���l�u���X�����t�@�ج���l�u�u"RED"���~�u"NOR"�v�g���I\n"NOR, this_object(), enemy);
                for(i=0;i<sizeof(targets);i++) {
                    if( i == 4 ) break;

                    evade = COMBAT_D->wittiness(targets[i], 1)*1.5;

                    if( !COMBAT_D->SkillHit(this_object(), targets[i], exact, evade) ) {
                        message_vision("�S�Q�����l�u�o�g��~�M�z�����g�����A�i���S����$n\n", this_object(), targets[i] );
                    } else {
                        raiseDamage = 250;

                        add_temp("apply/attack", raiseDamage); 
                        damage = COMBAT_D->isDamage(this_object(), targets[i], query_temp("weapon/twohanded"));
                        add_temp("apply/attack", -raiseDamage);

                        if( damage < 100 ) damage = random(20) + 80;

                        // �ˮ`�ާl��
                        damage = COMBAT_D->receive_damage(targets[i], this_object(), damage);
                        targets[i]->receive_damage(damage, this_object());
                        message_vision( sprintf("����l�u�o�g��ߨ��z�����g�|�P�A���n�g���F$n�y���ˮ`(%d) %s\n", damage, COMBAT_D->report_status(targets[i]) ), this_object(), targets[i]);
                    }
                }
                message_vision("\n", this_object());
                this_object()->start_busy(2);
            }
            break;
    }
    return;
}