#include "CommandBriefingDialogModel.h"
#include "missionui/missioncmdbrief.h"


namespace fso {
namespace fred {
namespace dialogs {

	CommandBriefingDialogModel::CommandBriefingDialogModel(QObject* parent, EditorViewport* viewport) :
		AbstractDialogModel(parent, viewport),
		_briefingText(""),
		_animationFilename(""),
		_speechFilename(""),
		_currentTeam(0),
		_currentStage(-1),
		_waveID(0)
	// don't seem to need an initializeData()
{ // don't seem to need a body on this function, either
}

bool CommandBriefingDialogModel::apply()
{
	return true;
}

void CommandBriefingDialogModel::reject() {}

void CommandBriefingDialogModel::update_init()
{

	if (_currentStage >= 0) {
		_command_brief.num_stages = this->_totalStages;
//		_command_brief.background[0][0];
	}
}
}
}
}