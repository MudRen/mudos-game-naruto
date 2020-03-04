void do_fight()
{
    string dogname;
    int damage, raiseDamage, x, y, exact, evade;
    object enemy, me, mob, ob;
    mapping cnd = ([]);

    string *name1 = ({ "Ĭ", "�t", "��", "�x�T", "�R", "�T", "�R��", "��", "��", "��","�l", 
                       "�w", "�_", "�R�sıù", "�R", "��", "�ڹ�", "�L", "��", "��J", "��", 
                       "�ܩR", "�o�b" , "�d", "��", "�J", "��", "��", "�ǧJ", "�ڤ�" });

    string *name3 = ({ "��", "�~", "��", "��", "��" });

    // �S���ĤH
    me = this_object();
    enemy = me->query_opponent();
    if( !enemy ) return;

    // �ĤH�b���P��m
    if( environment(me)->is_area() ) {
        if( !area_environment(me, enemy) ) return;
    } else {
        if( environment(enemy) != environment(me) ) return;
    }

    switch( me->query("sktree") ) {
        case 1: // ���A�d�ڦN
            if( random(4) > 1 ) {
                message_vision("\n$N�|�P�ֳt«�_�j�q�@���A�uť$N���D�u"HIY"�K��"NOR"�E"HIW"�������H�ƥ�"NOR"�I�v\n", me, enemy);

                raiseDamage = me->query_attr("str")*2;
                if( damage > 70) raiseDamage = 70;

                raiseDamage += me->query_skill("blade");

                add_temp("apply/attack", raiseDamage); 
                damage = COMBAT_D->isDamage(me, enemy, 0);
                add_temp("apply/attack", -raiseDamage);

                // �P�_�R��
                if( !COMBAT_D->isHit(me, enemy) ) {
                    message_vision("���O�@���ܧִN���F�}�ӡA�ä���$N�����v�C\n\n", me, enemy);
                    me->damage_stat("mp", 20, me);
                    me->start_busy(2);
                    return;
                }
                enemy->receive_damage(damage, me);
                message_vision( sprintf("$n�Q�@�����л\�䤣��$N���ܸ�A���G�Q������ˤF(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), me, enemy);
                me->damage_stat("mp", 10, me);
                me->start_busy(1);
            } else {
                message_vision("\n$N�ʵۤs���@���ĤѡI���M�b�Ť��@�ޡy"HIY"����"NOR"�E"YEL"�W���n�s"NOR"�z�q�Ѧӭ���V$n�I\n", me, enemy);

                raiseDamage = me->query_skill("blade");

                add_temp("apply/attack", raiseDamage); 
                damage = COMBAT_D->isDamage(me, enemy, 0);
                add_temp("apply/attack", -raiseDamage);

                exact = COMBAT_D->exact(me, enemy, 1) + COMBAT_D->intimidate(me, 1);
                evade = COMBAT_D->evade(enemy, me, 1) + COMBAT_D->wittiness(enemy, 1);

                if( !COMBAT_D->SkillHit(me, enemy, exact, evade) ) {
                    message_vision("$N���ߤ�í�A�ۤv�q�Ť��^�F�U�ӡC\n\n", me, enemy);
                    me->damage_stat("mp", 20, me);
                    me->start_busy(2);
                    return;
                }
                // �ˮ`�ާl��
                damage = COMBAT_D->receive_damage(enemy, me, damage);
                enemy->receive_damage(damage, me);
                message_vision( sprintf("$n���פ���Q���t���U���Q�b�Ҩ��(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), me, enemy);
                me->damage_stat("mp", 20, me);
                me->start_busy(1);
            }
            break;

        case 2: // �r�~�ϼ��_
            x = me->query("area_info/x_axis");
            y = me->query("area_info/y_axis");
            mob = new(__DIR__"dog.c");
            dogname = name1[random(sizeof(name1))] + name3[random(sizeof(name3))];

            if( me->query_temp("dog_clone") != 1 ) {
                message_vision("$N"HIY"�|��j�_�f��A�q����]�X�@��"NOR+dogname+HIY"�C\n"NOR, me);
                if( environment(me)->is_area() ) {
                    mob->set("name", dogname);
                    if( area_move(environment(me), mob, x, y) ) {
                        mob->guard_ob(me);
                        mob->set_leader(me);
                        me->guard_ob(mob);

                        mob->kill_ob(enemy);
                        if( function_exists("accept_kill", enemy) && !enemy->is_killing(mob) && enemy->accept_kill(mob) ) return;
                        if( !enemy->is_killing(mob) ) enemy->kill_ob(mob);

                        me->set_temp("dog_clone", 1);
                        return;
                    }
                    message_vision("���O$N�޳N�Ӯt�A�j���X�n���C\n", me);
                    do_chat((: random_move :));
                    return;
                }
                message_vision("���O�o�̬O�ж��A�n���Ǥ��X�h�C\n", me);
                do_chat((: random_move :));
                return;
            } else {
                if( !present("_ANIMAL_", environment(me)) ) message_vision("$N���۵ۡG"HIG"�d�����A�]����̥h�աI\n"NOR, me);
                message_vision("\n$N�I�s�d���i��y"HIW"�H�~�X��"NOR"�z$N�����@�l���_$n���h�����d�����W�I\n", me, enemy);

                exact = COMBAT_D->exact(me, enemy, 1)/2;
                add_temp("apply/exact", exact);

                if( !COMBAT_D->isHit(me, enemy) ) {
                    message_vision("���O����ڥ��N�S���t�X�n�A$N�k�L�F�@�T�C\n\n", enemy);
                    me->damage_stat("mp", 10, me);
                    me->start_busy(2);
                } else {
                    raiseDamage = me->query_skill("activity")*4/5;

                    add_temp("apply/attack", raiseDamage); 
                    damage = COMBAT_D->isDamage(me, enemy, 0);
                    add_temp("apply/attack", -raiseDamage);

                    enemy->receive_damage(damage, me);
                    me->damage_stat("mp", 20, me);
                    message_vision( sprintf("�r�~�R�q�@�n���V$n�A�q$n�����W�r�U�F�@���סI(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), me, enemy);
                    me->start_busy(1);
                }
                add_temp("apply/exact", -exact);
                return;
            }
            break;

        case 3: // �¿߲���J��
            message_vision("\n$N����U���������k�n�\�A�t�X"HIM"�L�v�}"NOR"���k�ϥX�ħڤ�������"HIR"�y"HIK+BLINK"�@��"NOR+HIR"�z\n"NOR, me, enemy);

            exact = COMBAT_D->exact(me, enemy, 1)/3;
            add_temp("apply/exact", exact);

            if( !COMBAT_D->isHit(me, enemy) ) {
                message_vision("$n�J�ô��R��ܡA�ꥩ�פU�F$N�������C\n\n", me, enemy);
                me->damage_stat("mp", 10, me);
                me->start_busy(1);
            } else {
                raiseDamage = me->query_skill("martial") + 15;

                add_temp("apply/attack", raiseDamage); 
                damage = COMBAT_D->isDamage(me, enemy, 0);
                add_temp("apply/attack", -raiseDamage);

                // �ˮ`�ާl��
                damage = COMBAT_D->receive_damage(enemy, me, damage);
                enemy->receive_damage(damage, me);
                me->damage_stat("mp", 20, me);
                message_vision( sprintf("�u���v���n�L�Ƥ��b�q�|���K�赹��$n�Y���ˮ`(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), me, enemy);
                me->start_busy(1);
            }
            add_temp("apply/exact", -exact);
            break;

        case 4: // �ʯv�v�ǧJ��
            exact = COMBAT_D->exact(me, enemy, 1);
            add_temp("apply/exact", exact)/4;

            if( !enemy->is_busy() ) {
                message_vision("\n$N���_�Z�����k�n�̻��G"HIG"��ڻ��@�B�G�B$N"HIG"�I"NOR"$n"HIG"�N�|�εۡI\n"NOR, me, enemy);
                if( !COMBAT_D->isHit(me, enemy) ) {
                    message_vision("$N�H�ỡ�D�G"HIG"�@�I�G�I$N�I...���G�L�ۤv�εۤF...\n\n"NOR, me, enemy);
                    me->damage_stat("mp", 20, me);
                    me->start_busy(4);
                } else {
                    me->damage_stat("mp", 20, me);
                    message_vision("$N�H�ỡ�D�G"HIG"�@�I�G�I$N�I...���G"NOR"$n"HIG"�v���Q�ʯv�ӺεۤF�C\n\n"NOR, me, enemy);
                    me->start_busy(1);
                    enemy->start_busy(3);
                }
            } else {
                message_vision("\n$N�N�Z���ֳt����u"HIW"��b"NOR"�v�ֳt���Y�V�L�k��ʪ�$n�I\n", me, enemy);
                if( !COMBAT_D->isHit(me, enemy) ) {
                    message_vision("���O$N��������V���G�S����ǡA�u���F�X���𸭡C\n\n", me, enemy);
                    me->damage_stat("mp", 20, me);
                    me->start_busy(1);
                } else {
                    raiseDamage = me->query_skill("martial")/2;

                    add_temp("apply/attack", raiseDamage); 
                    damage = COMBAT_D->isDamage(me, enemy, 0);
                    add_temp("apply/attack", -raiseDamage);

                    enemy->receive_damage(damage, me);
                    me->damage_stat("mp", 20, me);
                    message_vision( sprintf("�u�ԡv�a�@�n����$n�A$n���еh�W����(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), me, enemy);
                    me->start_busy(1);
                }
            }
            add_temp("apply/exact", -exact);
            break;

        case 5: // ���H����
            if( random(4) > 1 ) {
                message_vision("\n$N�����W�u"HIK"�]��y"NOR"�v���M���t�ĦV$n�H���O�[�t�ץ���$n�I\n", me, enemy);

                exact = COMBAT_D->exact(me, enemy, 1)/2;
                add_temp("apply/exact", exact);

                if( !COMBAT_D->isHit(me, enemy) ) {
                    message_vision("$N���l�@�n�׹L�F�o��������...\n\n", enemy);
                    me->damage_stat("mp", 10, me);
                    me->start_busy(3);
                } else {
                    raiseDamage = me->query_skill("spurn");

                    add_temp("apply/attack", raiseDamage); 
                    damage = COMBAT_D->isDamage(me, enemy, 0);
                    add_temp("apply/attack", -raiseDamage);

                    enemy->receive_damage(damage, me);
                    me->damage_stat("mp", 20, me);
                    message_vision( sprintf("$n�{�פ��ΡA�Q�{�����_���P...�R�X�@�f�A��(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), me, enemy);
                    me->start_busy(1);
                    enemy->start_busy(1);
                }
            } else {
                message_vision("\n$N�N�]��y�Ϥ����A�@�O�u"HIR"�Ϥⰼ��"NOR"�v�{�V$n���ӻH�C\n", me, enemy);

                exact = COMBAT_D->exact(me, enemy, 1)*1.7;
                evade = COMBAT_D->evade(enemy, me, 1)*1.5;

                if( !COMBAT_D->SkillHit(me, enemy, exact, evade) ) {
                    message_vision("$N�y�L����@�h�׶}�F�����C\n\n", enemy);
                    me->damage_stat("mp", 20, me);
                    me->start_busy(2);
                } else {
                    raiseDamage = me->query_skill("spurn")*2/3;

                    add_temp("apply/attack", raiseDamage); 
                    damage = COMBAT_D->isDamage(me, enemy, 0);
                    add_temp("apply/attack", -raiseDamage);

                    // �ˮ`�ާl��
                    damage = COMBAT_D->receive_damage(enemy, me, damage);
                    enemy->receive_damage(damage, me);
                    message_vision( sprintf("�u�S�v�a�@�n�A��y����$n�ӻH�A���ˤF$n(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), me, enemy);
                    me->damage_stat("mp", 20, me);
                    me->start_busy(1);
                }
            }
            break;

        case 6: // �K���ک�
            if( enemy->query_condition("firelotus") ) return;
            message_vision("\n$N���������K���i�����Ͱ����y"HIM"���K$N"NOR"�z�K���@���P���Q�V$n�I\n", me, enemy);

            exact = COMBAT_D->intimidate(me, 1);
            evade = COMBAT_D->wittiness(enemy, 1);

            if( !COMBAT_D->SkillHit(me, enemy, exact, evade) ) {
                message_vision("���K�N��@�b���M�ֳt��z�Ӯ����p�ɤF�C\n\n", enemy);
                me->damage_stat("mp", 20, me);
                me->start_busy(2);
            } else {
                add_temp("apply/attack", 60); 
                damage = COMBAT_D->isDamage(me, enemy, 0);
                add_temp("apply/attack", -60);

                enemy->receive_damage(damage, me);
                message_vision( sprintf("���K�b$n�|�P�z�}�A�Φ��@������������(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), me, enemy);
                me->damage_stat("mp", 30, me);
                me->start_busy(1);

                cnd["name"] = HIR+"���K�ک�"+NOR;
                cnd["duration"] = 5;
                cnd["from"] = me;

                enemy->set_condition("firelotus", cnd);
            }
            break;
    }
}