#ifndef POGADESOURCECODEEDITOR_H
#define POGADESOURCECODEEDITOR_H

#include <QWidget>
#include <QDockWidget>
#include <QTemporaryDir>
#include <QSignalMapper>

#include "sourcecodeeditor.h"
#include "pogadeprojectsourcefile.h"
#include "pogadegraphviewer.h"

// Selected Pragma
#define SC_MARK_PSEL_LINE 0
#define SC_MARK_PSEL_SYMB 1

// Selected Pragma Scope
#define SC_MARK_PPSEL_LINE 2
#define SC_MARK_PPSEL_SYMB 3

// Show Pragma
#define SC_MARK_P_LINE 4
#define SC_MARK_P_SYMB 5

// Arrow marker
#define SC_MARK_ARROW 8

typedef struct {
  QString code;
  int endCol;
  int endLine;
  int len;
  QString pragma;
  int pragmaLine;
  int start;
  int startCol;
  int startLine;
  /* function information */
  QString funcName;
  std::vector<QString> paramVarName;
  std::vector<int> paramVarPos;
  std::vector<QString> pragmaVarName;
  std::vector<int> pragmaVarPos;
} pragma_t;


namespace Ui {
  class PogadeSourceCodeEditor;
}

class PogadeSourceCodeEditor : public QWidget
{
  Q_OBJECT

public:
  explicit PogadeSourceCodeEditor(QWidget *parent = 0);
  ~PogadeSourceCodeEditor();
  void setSourceFile(PogadeProjectSourceFile* source = nullptr);
  void setDock(QDockWidget * dock);
  bool fileChanged();
  PogadeProjectSourceFile* sourceFile();
  void setTDir(QTemporaryDir *tDir);

public slots:
  void updateGUI();
  void cleanExit(bool visibility);
  void saveFile();
  void selectedPragmaAndScope(PolcaScope ps, PolcaPragma pp);
  void selectedScope(PolcaScope ps);
  void scopeSelectedUPProcess(int id);
  void transformationClick(int,int,Qt::KeyboardModifiers);
  void transAction(QString id);
  //void updateTransformations();
  void showTransformations();
  void replaceCode(QString newCode);
  void asmCountCode(QString file, QString flags);
  void processASMCountCode(QString data);
  void polcaProcessCode();

  void polcaProcessCodeScopes();
  void polcaProcessCodeTransformations();
  void polcaProcessCodeASMC();

signals:
  void printNumberElements();
  void createNV(PogadeProjectSourceFile*);
  void createST(PogadeProjectSourceFile*);
  void createTR(PogadeProjectSourceFile*);
  void scopeSelectedDown(int);
  void repaint();
  void transformationSelectedDown(int);
  void newTransformations();

private slots:
  void lineDoubleClick(int line);
  void onTextChanged();
  void newRevision();
  void createRevision(QString revName);
  void resetComboRevision(int selectedRevision);
  void enableEdit(bool enable);
  void revisionSelectionChanged(int newSelection);
  //void loadPolcaProcessing(QString file);
  void loadPolcaProcessingData(QString data);
  void loadPolcaTransformationsData(QString data);
  void showPragmas();
  void viewTransformations();
  void viewGraph();
  void viewTree();
  //void makeStandard();

  void showMemory(int show);

private:
  Ui::PogadeSourceCodeEditor *ui;
  SourceCodeEditor *se;
  PogadeProjectSourceFile* sf = nullptr;
  QDockWidget * _dock = nullptr;
  bool _fileLoaded = false;
  bool _currentChanged = false;
  int _oldComboSelect = -1;
  PogadeGraphViewer *_gv = nullptr;
  QTemporaryDir *_tDir;

  QSignalMapper *signalMapper = nullptr;
};

#endif // POGADESOURCECODEEDITOR_H
