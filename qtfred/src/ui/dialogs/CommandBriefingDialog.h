#ifndef COMMANDBRIEFEDITORDIALOG_H
#define COMMANDBRIEFEDITORDIALOG_H

#include <QtWidgets/QDialog>
#include <mission/dialogs/CommandBriefingDialogModel.h>
#include <ui/FredView.h>

#include <QAbstractButton>
#include <QtWidgets/QDialog>


namespace fso {
namespace fred {
namespace dialogs {

namespace Ui {
class CommandBriefingDialog;
}

class CommandBriefingDialog : public QDialog {

	Q_OBJECT

public:

	explicit CommandBriefingDialog(FredView* parent, EditorViewport* viewport);
	~CommandBriefingDialog() override;

protected:
	void closeEvent(QCloseEvent*) override;

private slots: // where the buttons go
	void on_previousStageButton_clicked();
	void on_nextStageButton_clicked();
	void on_addStageButton_clicked();
	void on_insertStageButton_clicked();
	void on_deleteStageButton_clicked();
	void on_changeTeams_clicked();
	void on_copyToOtherTeams_clicked();
	void on_browseAnimationFile_clicked();
	void on_browseSoundFile_clicked();
	void on_testSoundFile_clicked();

private:
	std::unique_ptr<Ui::CommandBriefingDialog> ui;
	std::unique_ptr<CommandBriefingDialogModel> _model;
	EditorViewport* _viewport;

	void updateUI();

	// when fields get updated
	void briefingTextChanged(const QString&);
	void animationFilenameChanged(const QString&);
	void speechFilenameChanged(const QString&);
};
} // namespace dialogs
} // namespace fred
} // namespace fso

#endif
