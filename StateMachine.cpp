#include "StateMachine.hpp"

#include <stack>

namespace Sonar
{
    void StateMachine::AddState( StateRef newState, bool isReplacing )
    {
        _isAdding = true;
        _isReplacing = isReplacing;
        
        _newState = std::move( newState );
        
    }
    
    void StateMachine::RemoveState( )
    {
        this->_isRemoving = true;
    }
    
    void StateMachine::ProcessStateChanges( )
    {
        if ( this->_isRemoving && !this->_states.empty( ) )
        {
            this->_states.pop( );
            
            //check again if the states are empty
            
            if ( !this->_states.empty( ) )
            {
                this->_states.top( )->Resume( );
            }
            this->_isRemoving = false;
        }
        
        if ( this->_isAdding )
        {
            if  ( !this->_states.empty( ) )
            {
                if ( this->_isReplacing)
                {
                    this->_states.pop( );
                }
                else
                {
                    this->_states.top( )->Pause( );
                }
            }
            
            this->_states.push( std::move( this->_newState) );
            this->_states.top( )->Init( ); //allow cool staff like textures
            this->_isAdding = false;
            
        }
    }
    
    StateRef &StateMachine::GetActiveState( )
    {
        return this->_states.top( );
    }

}



















