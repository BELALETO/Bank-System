#include "client.h"

Client::Client(QObject *parent)
    : QObject{parent}
{
    m_view = new View();
    m_control = new Control(this);
    connect(m_view, &View::makeRequest, m_control, &Control::makeRequest);
    connect(m_view, &View::RC_View_Control_Signal, m_control, &Control::RC_View_Control_Slot);

    connect(m_control, &Control::SH_Contor_View_connected_signal, m_view, &View::SH_Contor_View_connected_slot);
    connect(m_control, &Control::SH_Contor_View_disconnected_signal, m_view, &View::SH_Contor_View_disconnected_slot);

    connect(m_control, &Control::adminScreen_signal, m_view, &View::adminScreen_slot); // to view admin screen.
    connect(m_control, &Control::UserScreen_signal, m_view, &View::UserScreen_slot);   // to view admin screen.

    connect(m_control, &Control::CU_Control_Client, m_view, &View::CU_Client_View);
    connect(m_control, &Control::UU_Control_Client, m_view, &View::UU_Client_View);

    connect(m_control, &Control::DU_Control_Client, m_view, &View::DU_Client_View);

    connect(m_control, &Control::AN_Control_View_action, m_view, &View::AN_Control_View_action);
    connect(m_control, &Control::AB_Control_View_action, m_view, &View::AB_Control_View_action);
    connect(m_control, &Control::DB_Control_View_action, m_view, &View::DB_Control_View_action);

    connect(m_control, &Control::MT_Control_View_action, m_view, &View::MT_Control_View_action);
    connect(m_control, &Control::TA_Control_View_action, m_view, &View::TA_Control_View_action);

    connect(m_control, &Control::TH_Control_View_action, m_view, &View::TH_Control_View_action);


    //error connections

    connect(m_control, &Control::existUsr_Control_View_action, m_view, &View::existUsr_Control_View_action);
    connect(m_control, &Control::InvalidTransaction_Control_View_action, m_view, &View::InvalidTransaction_Control_View_action);
    connect(m_control, &Control::wrongUsr_Control_View_action, m_view, &View::wrongUsr_Control_View_action);
    connect(m_control, &Control::noUsr_Control_View_action, m_view, &View::noUsr_Control_View_action);
    connect(m_control, &Control::ServerError_Control_View_action, m_view, &View::ServerError_Control_View_action);

    connect(m_control, &Control::closedSocket_Control_View_signal, m_view, &View::closedSocket_Control_View_slot);



}



Client::~Client()
{
    delete m_view;
    delete m_control;
}



