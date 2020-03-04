void init()
{
    string msg;

    if( this_object() == this_player() ) return;

    // �Y this_player() �ݤ����o�ӤH���A�h���޵o�԰��C
    if( ! this_object()->visible(this_player()) ) return;

    // �ϰ�]�w
    if( environment()->is_area() && !area_environment(this_object(), this_player()) ) return;

    // �Y���西���ۤ������A�}�l�԰��C
    if( this_player()->is_killing(query("id")) ) {
        COMBAT_D->auto_fight(this_player(), this_object(), "hatred");
        return;
    }
    if( is_killing(this_player()->query("id")) )
    {
        COMBAT_D->auto_fight(this_object(), this_player(), "hatred");
        return;
    }
    // �J�����¾�~���N�D�ʧ���
    if( this_player()->query_class() == "little_sea" 
        || this_player()->query_class() == "thief_sea" 
        || this_player()->query_class() == "big_sea" 
        || this_player()->query_class() == "reward_sea" 
        || this_player()->query_class() == "money_sea"
        || this_player()->query_class() == "king_sea" ) {

        switch(random(4)) {
            case 0: msg = ""HIR"$N"HIR"�@����$n�ߨ�W�e�����G�u�����ŧ�I���O��$n���F�I�v"NOR"\n\n"; break;
            case 1: msg = ""HIR"$N"HIR"�@����$n�j�۵ۡG�u�O����I����ʭ��I�v"NOR"\n\n"; break;
            case 2: msg = ""HIR"$N"HIR"�o�{$n���W�۹D�G�u�o�̬O���x��a�I�i�c������O�Q�k���I�v"NOR"\n\n"; break;
            case 3: msg = ""HIR"$N"HIR"�@����$n�ߨ�W�e�����G�u�e�����q���W�I�v"NOR"\n\n"; break;
        }
        message_vision(msg, this_object(), this_player());
        this_object()->kill_ob(this_player());
        if( function_exists("accept_kill", this_player()) && !this_player()->is_killing(this_object()) && this_player()->accept_kill(this_object()) ) return;
        if( ! this_player()->is_killing(this_object()) ) this_player()->kill_ob(this_object());
    }
}
