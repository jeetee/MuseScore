/*
 * SPDX-License-Identifier: GPL-3.0-only
 * MuseScore-CLA-applies
 *
 * MuseScore
 * Music Composition & Notation
 *
 * Copyright (C) 2021 MuseScore BVBA and others
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef MU_APP_APP_H
#define MU_APP_APP_H

#include <QList>

#include "modularity/imodulesetup.h"
#include "modularity/ioc.h"
#include "global/iapplication.h"
#ifdef MUE_BUILD_CONVERTER_MODULE
#include "converter/iconvertercontroller.h"
#endif
#ifdef MUE_BUILD_DIAGNOSTICS_MODULE
#include "diagnostics/idiagnosticdrawprovider.h"
#endif
#ifdef MUE_BUILD_AUTOBOT_MODULE
#include "autobot/iautobot.h"
#endif
#include "audio/iregisteraudiopluginsscenario.h"
#include "multiinstances/imultiinstancesprovider.h"

#ifdef MUE_BUILD_UI_MODULE
#include "ui/iuiconfiguration.h"
#endif
#include "notation/inotationconfiguration.h"
#include "project/iprojectconfiguration.h"
#include "playback/isoundprofilesrepository.h"
#ifdef MUE_BUILD_APPSHELL_MODULE
#include "appshell/iappshellconfiguration.h"
#include "appshell/internal/istartupscenario.h"
#endif
#ifdef MUE_BUILD_IMPORTEXPORT_MODULE
#include "importexport/imagesexport/iimagesexportconfiguration.h"
#include "importexport/midi/imidiconfiguration.h"
#include "importexport/audioexport/iaudioexportconfiguration.h"
#ifdef MUE_BUILD_VIDEOEXPORT_MODULE
#include "importexport/videoexport/ivideoexportconfiguration.h"
#endif
#include "importexport/guitarpro/iguitarproconfiguration.h"
#else
#ifdef MUE_BUILD_IMAGESEXPORT_MODULE
#include "importexport/imagesexport/iimagesexportconfiguration.h"
#endif
#endif

#include "commandlineparser.h"

namespace mu::app {
class App
{
    INJECT(framework::IApplication, muapplication)
#ifdef MUE_BUILD_CONVERTER_MODULE
    INJECT(converter::IConverterController, converter)
#endif
#ifdef MUE_BUILD_DIAGNOSTICS_MODULE
    INJECT(diagnostics::IDiagnosticDrawProvider, diagnosticDrawProvider)
#endif
#ifdef MUE_BUILD_AUTOBOT_MODULE
    INJECT(autobot::IAutobot, autobot)
#endif
    INJECT(audio::IRegisterAudioPluginsScenario, registerAudioPluginsScenario)
    INJECT(mi::IMultiInstancesProvider, multiInstancesProvider)
#ifdef MUE_BUILD_UI_MODULE
    INJECT(ui::IUiConfiguration, uiConfiguration)
#endif
#ifdef MUE_BUILD_APPSHELL_MODULE
    INJECT(appshell::IAppShellConfiguration, appshellConfiguration)
    INJECT(appshell::IStartupScenario, startupScenario)
#endif
    INJECT(notation::INotationConfiguration, notationConfiguration)
    INJECT(project::IProjectConfiguration, projectConfiguration)
    INJECT(playback::ISoundProfilesRepository, soundProfilesRepository)
#ifdef MUE_BUILD_IMPORTEXPORT_MODULE
    INJECT(iex::imagesexport::IImagesExportConfiguration, imagesExportConfiguration)
    INJECT(iex::midi::IMidiImportExportConfiguration, midiImportExportConfiguration)
    INJECT(iex::audioexport::IAudioExportConfiguration, audioExportConfiguration)
#ifdef MUE_BUILD_VIDEOEXPORT_MODULE
    INJECT(iex::videoexport::IVideoExportConfiguration, videoExportConfiguration)
#endif
    INJECT(iex::guitarpro::IGuitarProConfiguration, guitarProConfiguration)
#else
#ifdef MUE_BUILD_IMAGESEXPORT_MODULE
    INJECT(iex::imagesexport::IImagesExportConfiguration, imagesExportConfiguration)
#endif
#endif

public:
    App();

    int run(CommandLineParser& commandLineParser);

protected:
    void addModule(modularity::IModuleSetup* module);
    void addModules();

private:
    void applyCommandLineOptions(const CommandLineParser::Options& options, framework::IApplication::RunMode runMode);
    int processConverter(const CommandLineParser::ConverterTask& task);
    int processDiagnostic(const CommandLineParser::Diagnostic& task);
    int processAudioPluginRegistration(const CommandLineParser::AudioPluginRegistration& task);
    void processAutobot(const CommandLineParser::Autobot& task);

    QList<modularity::IModuleSetup*> m_modules;
};
}

#endif // MU_APP_APP_H
