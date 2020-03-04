int num=0;

void do_check()
{
    if( num > 0) {
        set("chat_chance", 10);
        this_object()->heal_stat("hp", num);
        message_vision( sprintf("$N"HIW"�q�a�W�߰_�e���ɥR��~���Ӱ��Y���ˮ`(%d) %s\n\n", num, COMBAT_D->report_status(this_object()) ), this_object());
        num = 0;
        return;
    }
    message_vision(CYN"$N�ˬd�ۥ|�P���S���ĤH....\n"NOR, this_object());
    return;
}

void do_fight()
{
    int damage, raiseDamage, i, exact, evade;
    object enemy, item;
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
    switch( random(5) ) {
        case 0: // ��Q���R-�����h�H
            num = num + 30;
            this_object()->receive_damage(15, this_object());
            message_vision("\n$N"NOR"�q���W�z�X�X�ڰ��Y�ϥX�u"HIY"��Q���R"NOR"�v���Y���p�}���g�V�|�P�I\n"NOR, this_object(), enemy);
            for(i=0;i<sizeof(targets);i++) {
                if( i == this_object()->query_level()/10 ) break;   // �ӵ��ŧ����H�ơB�褧���O6�H ��L���]�O3�H
                if( !COMBAT_D->isHit(this_object(), targets[i]) ) {
                    message_vision("���Y�w�w�w�a�������a���O�A���O�o�S������$N\n", targets[i], this_object());
                    this_object()->start_busy(2);
                } else {
                    raiseDamage = this_object()->query_level()*7;

                    add_temp("apply/attack", raiseDamage); 
                    damage = COMBAT_D->isDamage(this_object(), enemy, query_temp("weapon/righthand"));
                    add_temp("apply/attack", -raiseDamage);

                    if( damage < 150 ) damage = this_object()->query_level()*3 + random(50);

                    // �ˮ`�ާl��
                    damage = COMBAT_D->receive_damage(targets[i], this_object(), damage);
                    targets[i]->receive_damage(damage, this_object());
                    message_vision( sprintf("���Y�@�L�ؼЦa�îg�A�o���n�g���F$n�y���@�Ƕˮ`(%d) %s\n", damage, COMBAT_D->report_status(targets[i]) ), this_object(), targets[i]);
                    targets[i]->start_busy(1);
                }
            }
            message_vision("\n", this_object());
            break;
        case 1: // �K�u�ᤧ�R-����ˮ`
            num = num + 50;
            exact = COMBAT_D->intimidate(this_object(), 1)*1.5;
            evade = COMBAT_D->wittiness(enemy, 1);

            this_object()->receive_damage(25, this_object());
            message_vision("\n$N"NOR"�Ⱙ�����z�X�A�ܦ����p��j�몺�u"HIR"�K�u�ᤧ�R"NOR"�v�W�V$n���ݤf�I\n"NOR, this_object(), enemy);
            if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
                message_vision("$N�����ਭ�N�����O�D�I�O�b�j�����y���A��$n�����������F��V�C\n\n", enemy, this_object());
                this_object()->start_busy(1);
            } else {
                raiseDamage = this_object()->query_level()*10;

                add_temp("apply/attack", raiseDamage); 
                damage = COMBAT_D->isDamage(this_object(), enemy, query_temp("weapon/righthand"));
                add_temp("apply/attack", -raiseDamage);

                if( damage < 140 ) damage = this_object()->query_level()*4 + random(50);

                enemy->receive_damage(damage, this_object());
                message_vision( sprintf("$n���O�{�ק����A�o���M�Q�j���뤤���骺�����A�Φ��@�Ӧ�y�p�W���]�K(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
            }
            break;
        case 2: // �ҩ]���R-�s��ˮ`
            num = num + 50;
            exact = COMBAT_D->exact(this_object(), enemy, 1)/5;
            add_temp("apply/exact", exact);

            this_object()->receive_damage(25, this_object());
            message_vision("\n$N"NOR"�N�Q�ڤ����ǤF$n�u"HIM"�ҩ]���R"NOR"�v���Y�u�I�I�I�v�a�����j��g��$n�I\n"NOR, this_object(), enemy);
            for(i=0;i<3;i++) {
                if( !COMBAT_D->isHit(this_object(), enemy) ) {
                    message_vision("���G�����S������$N...\n", enemy, this_object());
                } else {
                    raiseDamage = this_object()->query_level()*5;

                    add_temp("apply/attack", raiseDamage); 
                    damage = COMBAT_D->isDamage(this_object(), enemy, query_temp("weapon/righthand"));
                    add_temp("apply/attack", -raiseDamage);

                    if( damage < 50 ) damage = this_object()->query_level() + random(25);

                    // �ˮ`�ާl��
                    damage = COMBAT_D->receive_damage(enemy, this_object(), damage);
                    enemy->receive_damage(damage, this_object());
                    message_vision( sprintf("$n�u�P�v�a�@�n�Q�����W�X�F�@�D�ˤf(%d) %s\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
                }
            }
            add_temp("apply/exact", -exact);
            message_vision("\n", this_object());
            break;
        case 3: // �������R-���ˮ`
            num = num + 200;
            exact = COMBAT_D->intimidate(this_object(), 1);
            evade = COMBAT_D->wittiness(enemy, 1);

            this_object()->receive_damage(100, this_object());
            message_vision("\n$N"NOR"���l���a�U�@�I�A�ϥX�˩R����"HIY"�y"HIR+BLINK"�������R"NOR+HIY"�z"NOR"�������Y�W�V�|���K��I\n"NOR,this_object(), enemy);

            if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
                message_vision("�L�ư��Y�q�a�����ĦӤW�A�N�|�P�릨���s�A���O�S����$N...\n\n", enemy, this_object());
                this_object()->start_busy(2);
            } else {
                raiseDamage = this_object()->query_level()*20;

                add_temp("apply/attack", raiseDamage); 
                damage = COMBAT_D->isDamage(this_object(), enemy, query_temp("weapon/righthand"));
                add_temp("apply/attack", -raiseDamage);

                if( damage < 350 ) damage = this_object()->query_level()*10 + random(100);

                enemy->receive_damage(damage, this_object());
                message_vision( sprintf("�u�P�P�v�s��X�n�A$n���w�Q�W�����ۡA���b���⪺��y��(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
                this_object()->start_busy(1);
            }
            break;
        case 4: // �ᰩ�C
            if( this_object()->query_temp("weapon/righthand") != 0 ) break;

            item = new(__DIR__"wp/spinal.c");
            num = num + 300;

            this_object()->receive_damage(150, this_object());
            message_vision(HIW"$N�I�i�_�F�u"NOR+YEL"�s�����R"HIW"�v�N�I�������հ��ޤF�X�ӡI\n"NOR, this_object());
            item->move(this_object());
            item->wield("righthand");
            break;
    }
    return;
}
