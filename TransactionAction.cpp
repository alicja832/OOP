#include "TransactionAction.h"
using namespace Transaction;
AccountState::AccountState(UndoAction *undo):_msg{undo}
    {
        _msg->Init();
        ok=false;
    }
AccountState::~AccountState()
    {
        if(ok) _msg->Ok();
        else
        { 
            _msg->Set_oryginal();
            _msg->Fail();
        }

        if(_msg)
            delete _msg;
    }
void AccountState::AllOk()
    {
        ok=true;
    }
bool AccountState::ok=false;