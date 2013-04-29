using System;
using System.Collections.Generic;
using System.Text;
using Brainiac.Design;
using Brainiac.Design.Attributes;
using BlankPlugin.Properties;

namespace BlankPlugin.Nodes
{
	public class ActionBlankNode : Brainiac.Design.Nodes.Action
	{
		protected int _exampleProperty= 5;

		[DesignerInteger("ActionBlankExampleProperty", "ActionBlankExamplePropertyDesc", "CategoryBasic", DesignerProperty.DisplayMode.List, 0, DesignerProperty.DesignerFlags.NoFlags, 1, 10, 1, "UnitsMeters")]
		public int ExampleProperty
		{
			get { return _exampleProperty; }
			set { _exampleProperty= value; }
		}

		protected override void CloneProperties(Brainiac.Design.Nodes.Node newnode)
		{
			base.CloneProperties(newnode);

			ActionBlankNode node= (ActionBlankNode)newnode;
			node._exampleProperty= _exampleProperty;
		}

		public ActionBlankNode() : base(Resources.ActionBlank, Resources.ActionBlankDesc)
		{
		}
	}
}
