#include "../include/BaseStateMachine.hpp"
#include "../include/Logger.hpp"

BaseStateMachine::BaseStateMachine()
{
	m_currentState = nullptr;
}

BaseStateMachine::~BaseStateMachine()
{
	if (m_currentState != nullptr)
	{
		delete m_currentState;
		m_currentState = nullptr;
	}
}

void BaseStateMachine::Update(sf::RenderWindow& window, sf::Time elapsed)
{
	if (m_currentState != nullptr)
	{
		m_currentState->OnUpdate(window, elapsed);
	}
}

void BaseStateMachine::SwitchState(BaseState* nextState)
{
	Logger* logger = Logger::GetInstance();
	std::string stateName;

	if (m_currentState != nullptr)
	{
		stateName = typeid(m_currentState).name();
		logger->log(LogLevel::INFO, "Exiting State " + stateName);
		m_currentState->OnExit();
		delete m_currentState;
		m_currentState = nullptr;
	}

	m_currentState = nextState;

	stateName = typeid(m_currentState).name();
	logger->log(LogLevel::INFO, "Entering State " + stateName);
	m_currentState->OnEntry();
}
