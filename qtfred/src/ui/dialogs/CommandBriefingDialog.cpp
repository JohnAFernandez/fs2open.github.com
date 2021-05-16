#include "CommandBriefingDialog.h"

#include "ui_CommandBriefingDialog.h"

#include "iff_defs/iff_defs.h"
#include "mission/missionmessage.h"

#include <globalincs/linklist.h>
#include <ui/util/SignalBlockers.h>

#include <QCloseEvent>

namespace fso {
namespace fred {
namespace dialogs {


	CommandBriefingDialog::CommandBriefingDialog(FredView* parent, EditorViewport* viewport) {
		this->setFocus();
		ui->setupUi(this);

		connect(_model.get(), &AbstractDialogModel::modelChanged, this, &CommandBriefingDialog::updateUI);
		connect(this, &QDialog::accepted, _model.get(), &CommandBriefingDialogModel::apply);
		connect(viewport->editor, &Editor::currentObjectChanged, _model.get(), &CommandBriefingDialogModel::apply);
		connect(viewport->editor, &Editor::objectMarkingChanged, _model.get(), &CommandBriefingDialogModel::apply);


//		connect(ui->shipNameEdit,
//			static_cast<void (QLineEdit::*)(const QString&)>(&QLineEdit::textChanged),
//			this,
//			&ShipEditorDialog::shipNameChanged);

	}

	CommandBriefingDialog::~CommandBriefingDialog(){}

	void CommandBriefingDialog::closeEvent(QCloseEvent*){}

	void CommandBriefingDialog::on_previousStageButton_clicked(){}

	void CommandBriefingDialog::on_nextStageButton_clicked(){}

	void CommandBriefingDialog::on_addStageButton_clicked(){}

	void CommandBriefingDialog::on_insertStageButton_clicked(){}

	void CommandBriefingDialog::on_deleteStageButton_clicked(){}

	void CommandBriefingDialog::on_changeTeams_clicked (){}

	void CommandBriefingDialog::on_copyToOtherTeams_clicked(){}

	void CommandBriefingDialog::on_browseAnimationFile_clicked(){}

	void CommandBriefingDialog::on_browseSoundFile_clicked(){}

	void CommandBriefingDialog::on_testSoundFile_clicked(){}

	void CommandBriefingDialog::updateUI(){}

	void CommandBriefingDialog::briefingTextChanged(const QString&){}

	void CommandBriefingDialog::animationFilenameChanged(const QString&){}

	void CommandBriefingDialog::speechFilenameChanged(const QString&){}

} // dialogs
} // fred
} // fso