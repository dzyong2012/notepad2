#include "EditLexer.h"
#include "EditStyleX.h"

// https://en.wikipedia.org/wiki/PowerShell
// https://docs.microsoft.com/en-us/powershell/scripting/powershell-scripting

static KEYWORDLIST Keywords_PS1 = {{
"begin break catch continue data do dynamicparam else elseif end exit filter finally for foreach "
"from function if in local param private process return switch throw trap try until where while",
"add-computer add-content add-history add-member add-pssnapin add-type checkpoint-computer "
"clear-content clear-eventlog clear-history clear-host clear-item clear-itemproperty "
"clear-variable compare-object complete-transaction connect-wsman convertfrom-csv "
"convertfrom-securestring convertfrom-stringdata convert-path convertto-csv convertto-html "
"convertto-securestring convertto-xml copy-item copy-itemproperty debug-process "
"disable-computerrestore disable-psbreakpoint disable-psremoting disable-pssessionconfiguration "
"disable-wsmancredssp disconnect-wsman enable-computerrestore enable-psbreakpoint "
"enable-psremoting enable-pssessionconfiguration enable-wsmancredssp enter-pssession "
"exit-pssession export-alias export-clixml export-console export-counter export-csv "
"export-formatdata export-modulemember export-pssession foreach-object format-custom format-list "
"format-table format-wide get-acl get-alias get-authenticodesignature get-childitem get-command "
"get-computerrestorepoint get-content get-counter get-credential get-culture get-date get-event "
"get-eventlog get-eventsubscriber get-executionpolicy get-formatdata get-help get-history "
"get-host get-hotfix get-item get-itemproperty get-job get-location get-member get-module "
"get-pfxcertificate get-process get-psbreakpoint get-pscallstack get-psdrive get-psprovider "
"get-pssession get-pssessionconfiguration get-pssnapin get-random get-service get-tracesource "
"get-transaction get-uiculture get-unique get-variable get-verb get-winevent get-wmiobject "
"get-wsmancredssp get-wsmaninstance group-object import-alias import-clixml import-counter "
"import-csv import-localizeddata import-module import-pssession invoke-command invoke-expression "
"invoke-history invoke-item invoke-wmimethod invoke-wsmanaction join-path limit-eventlog "
"measure-command measure-object move-item move-itemproperty new-alias new-event new-eventlog "
"new-item new-itemproperty new-module new-modulemanifest new-object new-psdrive new-pssession "
"new-pssessionoption new-service new-timespan new-variable new-webserviceproxy new-wsmaninstance "
"new-wsmansessionoption out-default out-file out-gridview out-host out-null out-printer "
"out-string pop-location push-location read-host receive-job register-engineevent "
"register-objectevent register-pssessionconfiguration register-wmievent remove-computer "
"remove-event remove-eventlog remove-item remove-itemproperty remove-job remove-module "
"remove-psbreakpoint remove-psdrive remove-pssession remove-pssnapin remove-variable "
"remove-wmiobject remove-wsmaninstance rename-item rename-itemproperty "
"reset-computermachinepassword resolve-path restart-computer restart-service restore-computer "
"resume-service select-object select-string select-xml send-mailmessage set-acl set-alias "
"set-authenticodesignature set-content set-date set-executionpolicy set-item set-itemproperty "
"set-location set-psbreakpoint set-psdebug set-pssessionconfiguration set-service set-strictmode "
"set-tracesource set-variable set-wmiinstance set-wsmaninstance set-wsmanquickconfig "
"show-eventlog sort-object split-path start-job start-process start-service start-sleep "
"start-transaction start-transcript stop-computer stop-job stop-process stop-service "
"stop-transcript suspend-service tee-object test-computersecurechannel test-connection "
"test-modulemanifest test-path test-wsman trace-command undo-transaction unregister-event "
"unregister-pssessionconfiguration update-formatdata update-list update-typedata use-transaction "
"wait-event wait-job wait-process where-object write-debug write-error write-eventlog write-host "
"write-output write-progress write-verbose write-warning",
"ac asnp cat cd chdir clc clear clhy cli clp cls clv compare copy cp cpi cpp cvpa dbp del diff "
"dir ebp echo epal epcsv epsn erase etsn exsn fc fl foreach ft fw gal gbp gc gci gcm gcs gdr ghy "
"gi gjb gl gm gmo gp gps group gsn gsnp gsv gu gv gwmi h help history icm iex ihy ii ipal ipcsv "
"ipmo ipsn ise iwmi kill lp ls man md measure mi mkdir more mount move mp mv nal ndr ni nmo nsn "
"nv ogv oh popd ps pushd pwd r rbp rcjb rd rdr ren ri rjb rm rmdir rmo rni rnp rp rsn rsnp rv "
"rvpa rwmi sajb sal saps sasv sbp sc select set si sl sleep sort sp spjb spps spsv start sv swmi "
"tee type where wjb write"

, // 1
"importsystemmodules prompt psedit tabexpansion"

, NULL, NULL, NULL, NULL, NULL

, NULL, NULL, NULL, NULL, NULL, NULL, NULL
}};

static EDITSTYLE Styles_PS1[] = {
	EDITSTYLE_DEFAULT,
	{ MULTI_STYLE(SCE_POWERSHELL_COMMENT, SCE_POWERSHELL_COMMENTSTREAM, 0, 0), NP2StyleX_Comment, L"fore:#608060" },
	{ SCE_POWERSHELL_KEYWORD, NP2StyleX_Keyword, L"bold; fore:#FF8000" },
	{ MULTI_STYLE(SCE_POWERSHELL_STRING, SCE_POWERSHELL_CHARACTER, 0, 0), NP2StyleX_String, L"fore:#008000" },
	{ SCE_POWERSHELL_NUMBER, NP2StyleX_Number, L"fore:#FF0000" },
	{ SCE_POWERSHELL_OPERATOR, NP2StyleX_Operator, L"fore:#B000B0" },
	{ SCE_POWERSHELL_VARIABLE, NP2StyleX_Variable, L"fore:#003CE6" },
	{ MULTI_STYLE(SCE_POWERSHELL_CMDLET, SCE_POWERSHELL_FUNCTION, 0, 0), NP2StyleX_Cmdlet, L"fore:#804000; back:#FFF1A8" },
	{ SCE_POWERSHELL_ALIAS, NP2StyleX_Alias, L"bold; fore:#0080C0" },
};

EDITLEXER lexPS1 = {
	SCLEX_POWERSHELL, NP2LEX_PS1,
	EDITLEXER_HOLE(L"PowerShell Script", Styles_PS1),
	L"ps1; psc1; psd1; psm1",
	&Keywords_PS1,
	Styles_PS1
};
