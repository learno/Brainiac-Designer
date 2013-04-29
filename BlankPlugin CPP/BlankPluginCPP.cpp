////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2009, Daniel Kollmann
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification, are permitted
// provided that the following conditions are met:
//
// - Redistributions of source code must retain the above copyright notice, this list of conditions
//   and the following disclaimer.
//
// - Redistributions in binary form must reproduce the above copyright notice, this list of
//   conditions and the following disclaimer in the documentation and/or other materials provided
//   with the distribution.
//
// - Neither the name of Daniel Kollmann nor the names of its contributors may be used to endorse
//   or promote products derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
// FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY
// WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "BlankPluginCPP.h"
#include "ActionBlankNode.h"
#include "ExporterExample.h"

namespace BlankPluginCPP
{
	BlankPluginCPP::BlankPluginCPP()
	{
		_fileManagers->Add( gcnew FileManagerInfo(Brainiac::Design::FileManagers::FileManagerXML::typeid, L"Behavior XML (*.xml)|*.xml", L".xml") );

		_exporters->Add( gcnew ExporterInfo(Brainiac::Design::Exporters::ExporterCs::typeid, L"C# Behavior Exporter (Assign Properties)", true, L"C#Properties") );
		_exporters->Add( gcnew ExporterInfo(Brainiac::Design::Exporters::ExporterCsUseParameters::typeid, L"C# Behavior Exporter (Use Parameters)", true, "C#Parameters") );
		_exporters->Add( gcnew ExporterInfo(ExporterExample::typeid, L"Example Exporter", true, L"ExampleExporter") );

		NodeGroup ^actions= gcnew NodeGroup(L"Actions", NodeIcon::Action, nullptr);
		_nodeGroups->Add(actions);

		actions->Items->Add(ActionBlankNode::typeid);
	}
}
