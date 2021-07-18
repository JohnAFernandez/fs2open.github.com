#include "CommandBriefingDialog.h"

#include "ui_CommandBriefingDialog.h"

#include "iff_defs/iff_defs.h" // probably won't need these two...
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

	void CommandBriefingDialog::on_actionPrevStage_clicked(){}

	void CommandBriefingDialog::on_actionNextStage_clicked(){}

	void CommandBriefingDialog::on_actionAddStage_clicked(){}

	void CommandBriefingDialog::on_actionInsertStage_clicked(){}

	void CommandBriefingDialog::on_actionDeleteStage_clicked(){}

	void CommandBriefingDialog::on_actionChangeTeams_clicked (){}

	void CommandBriefingDialog::on_actionCopyToOtherTeams_clicked(){}

	void CommandBriefingDialog::on_actionBrowseAnimation_clicked(){}

	void CommandBriefingDialog::on_actionBrowseSpeechFile_clicked(){}

	void CommandBriefingDialog::on_actionTestSpeechFileButton_clicked(){}

	void CommandBriefingDialog::on_actionLowResolutionBrowse_clicked(){}

	void CommandBriefingDialog::on_actionHighResolutionBrowse_clicked(){}

	void CommandBriefingDialog::updateUI(){}

	void CommandBriefingDialog::briefingTextChanged(const QString& string)
	{
		_model->setBriefingText(string.toStdString());
	}

	void CommandBriefingDialog::animationFilenameChanged(const QString& string)
	{
		_model->setAnimationFilename(string.toStdString());
	}

	void CommandBriefingDialog::speechFilenameChanged(const QString& string)
	{
		_model->setSpeechFilename(string.toStdString());
	}

	void CommandBriefingDialog::lowResolutionFilenameChanged(const QString& string)
	{
		_model->setLowResolutionFilename(string.toStdString());
	}

	void CommandBriefingDialog::highResolutionFilenameChanged(const QString& string)
	{
		_model->setHighResolutionFilename(string.toStdString());
	}

} // dialogs
} // fred
} // fso