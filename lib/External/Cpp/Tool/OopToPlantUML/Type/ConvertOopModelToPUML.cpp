#include "Deamer/External/Cpp/Tool/OopToPlantUML/Type/ConvertOopModelToPUML.h"
#include "Deamer/External/Cpp/Tool/OopSyntaxRecognizer/Type/BaseTypeObject.h"
#include "Deamer/External/Cpp/Tool/OopSyntaxRecognizer/Type/ClassObject.h"
#include "Deamer/External/Cpp/Tool/OopSyntaxRecognizer/Type/EnumObject.h"
#include "Deamer/External/Cpp/Tool/OopSyntaxRecognizer/Type/FunctionArgument.h"
#include "Deamer/External/Cpp/Tool/OopSyntaxRecognizer/Type/FunctionObject.h"
#include "Deamer/External/Cpp/Tool/OopSyntaxRecognizer/Type/InterfaceObject.h"
#include "Deamer/External/Cpp/Tool/OopSyntaxRecognizer/Type/PropertyObject.h"
#include "Deamer/External/Cpp/Tool/OopSyntaxRecognizer/Type/StructObject.h"
#include "Deamer/External/Cpp/Tool/OopSyntaxRecognizer/Type/Type.h"
#include "Deamer/External/Cpp/Tool/OopToPlantUML/Template/ClassDiagram/ClassDiagramTemplate.h"
#include <memory>

std::string deamer::external::cpp::tool::ooptoplantuml::ConvertOopModelToPUML::ConvertOopModel(
	const oopsyntaxrecognizer::OopModel& oopModel)
{
	auto classDiagramTemplate = std::make_unique<ClassDiagramTemplate>();
	classDiagramTemplate->function_argument_->variable_field_separator_->Set("");

	for (auto* type : oopModel.GetTypes())
	{
		classDiagramTemplate->function_->variable_field_->Clear();
		classDiagramTemplate->property_->variable_field_->Clear();

		switch (type->GetCategory())
		{
		case oopsyntaxrecognizer::TypeCategory::standard:
		case oopsyntaxrecognizer::TypeCategory::unknown: {
			break;
		}
		case oopsyntaxrecognizer::TypeCategory::classobject: {
			classDiagramTemplate->type_name_->Set(type->GetTypeName());
			classDiagramTemplate->type_category_->Set("class");
			classDiagramTemplate->type_name_lhs_->Set(type->GetTypeName());
			ImplementProperties(
				classDiagramTemplate,
				static_cast<oopsyntaxrecognizer::ClassObject*>(type)->GetPublicProperties(),
				oopModel);
			ImplementProperties(
				classDiagramTemplate,
				static_cast<oopsyntaxrecognizer::ClassObject*>(type)->GetProtectedProperties(),
				oopModel);
			ImplementProperties(
				classDiagramTemplate,
				static_cast<oopsyntaxrecognizer::ClassObject*>(type)->GetPrivateProperties(),
				oopModel);
			ImplementFunctions(
				classDiagramTemplate,
				static_cast<oopsyntaxrecognizer::ClassObject*>(type)->GetPrivateFunctions(),
				oopModel);
			ImplementFunctions(
				classDiagramTemplate,
				static_cast<oopsyntaxrecognizer::ClassObject*>(type)->GetProtectedFunctions(),
				oopModel);
			ImplementFunctions(
				classDiagramTemplate,
				static_cast<oopsyntaxrecognizer::ClassObject*>(type)->GetPublicFunctions(),
				oopModel);

			for (auto* baseType :
				 static_cast<oopsyntaxrecognizer::ClassObject*>(type)->GetBaseTypes())
			{
				classDiagramTemplate->type_name_rhs_->Set(baseType->GetType()->GetTypeName());
				if (baseType->GetType()->GetCategory() ==
					oopsyntaxrecognizer::TypeCategory::interfaceobject)
				{
					classDiagramTemplate->interface_realisation_->ExpandVariableField();
				}
				else
				{
					classDiagramTemplate->inheritance_relation_->ExpandVariableField();
				}
			}
			classDiagramTemplate->class_declaration_->ExpandVariableField();
			break;
		}
		case oopsyntaxrecognizer::TypeCategory::structobject: {
			classDiagramTemplate->type_name_->Set(type->GetTypeName());
			classDiagramTemplate->type_category_->Set("class");
			classDiagramTemplate->type_name_lhs_->Set(type->GetTypeName());
			ImplementFunctions(
				classDiagramTemplate,
				static_cast<oopsyntaxrecognizer::StructObject*>(type)->GetPrivateFunctions(),
				oopModel);
			ImplementFunctions(
				classDiagramTemplate,
				static_cast<oopsyntaxrecognizer::StructObject*>(type)->GetProtectedFunctions(),
				oopModel);
			ImplementFunctions(
				classDiagramTemplate,
				static_cast<oopsyntaxrecognizer::StructObject*>(type)->GetPublicFunctions(),
				oopModel);
			classDiagramTemplate->class_declaration_->ExpandVariableField();

			for (auto* baseType :
				 static_cast<oopsyntaxrecognizer::StructObject*>(type)->GetBaseTypes())
			{
				classDiagramTemplate->type_name_rhs_->Set(baseType->GetType()->GetTypeName());
				if (baseType->GetType()->GetCategory() ==
					oopsyntaxrecognizer::TypeCategory::interfaceobject)
				{
					classDiagramTemplate->interface_realisation_->ExpandVariableField();
				}
				else
				{
					classDiagramTemplate->inheritance_relation_->ExpandVariableField();
				}
			}
			break;
		}
		case oopsyntaxrecognizer::TypeCategory::interfaceobject: {
			classDiagramTemplate->type_name_->Set(type->GetTypeName());
			classDiagramTemplate->type_category_->Set("interface");
			classDiagramTemplate->type_name_lhs_->Set(type->GetTypeName());
			ImplementFunctions(
				classDiagramTemplate,
				static_cast<oopsyntaxrecognizer::InterfaceObject*>(type)->GetPrivateFunctions(),
				oopModel);
			ImplementFunctions(
				classDiagramTemplate,
				static_cast<oopsyntaxrecognizer::InterfaceObject*>(type)->GetProtectedFunctions(),
				oopModel);
			ImplementFunctions(
				classDiagramTemplate,
				static_cast<oopsyntaxrecognizer::InterfaceObject*>(type)->GetPublicFunctions(),
				oopModel);
			classDiagramTemplate->interface_declaration_->ExpandVariableField();

			for (auto* baseType :
				 static_cast<oopsyntaxrecognizer::InterfaceObject*>(type)->GetBaseTypes())
			{
				classDiagramTemplate->type_name_rhs_->Set(baseType->GetType()->GetTypeName());
				if (baseType->GetType()->GetCategory() ==
					oopsyntaxrecognizer::TypeCategory::interfaceobject)
				{
					classDiagramTemplate->interface_realisation_->ExpandVariableField();
				}
				else
				{
					classDiagramTemplate->inheritance_relation_->ExpandVariableField();
				}
			}
			break;
		}
		case oopsyntaxrecognizer::TypeCategory::enumobject: {
			classDiagramTemplate->type_category_->Set("enum");
			ImplementEnumeration(classDiagramTemplate,
								 static_cast<oopsyntaxrecognizer::EnumObject*>(type));
			break;
		}
		}
	}

	return classDiagramTemplate->GetOutput();
}

void deamer::external::cpp::tool::ooptoplantuml::ConvertOopModelToPUML::ImplementFunctions(
	std::unique_ptr<deamer::external::cpp::tool::ooptoplantuml::ClassDiagramTemplate>&
		classDiagramTemplate,
	std::vector<deamer::external::cpp::tool::oopsyntaxrecognizer::FunctionObject*> functions,
	const oopsyntaxrecognizer::OopModel& oopModel)
{
	for (auto* function : functions)
	{
		classDiagramTemplate->function_argument_->variable_field_->Clear();
		classDiagramTemplate->function_name_->Set(function->GetName());
		classDiagramTemplate->function_type_->Set(function->GetReturnType()->GetTypeName());
		bool first = true;
		for (auto* argument : function->GetFunctionArguments())
		{
			if (first)
			{
				classDiagramTemplate->optional_comma_->Set("");
				first = false;
			}
			else
			{
				classDiagramTemplate->optional_comma_->Set(", ");
			}
			classDiagramTemplate->function_argument_name_->Set(argument->GetName());
			classDiagramTemplate->function_argument_type_->Set(argument->GetType()->GetTypeName());
			classDiagramTemplate->function_argument_->ExpandVariableField();
		}
		classDiagramTemplate->function_->ExpandVariableField();
	}
}

void deamer::external::cpp::tool::ooptoplantuml::ConvertOopModelToPUML::ImplementProperties(
	const std::unique_ptr<ClassDiagramTemplate>& classDiagramTemplate,
	const std::vector<oopsyntaxrecognizer::PropertyObject*>& properties,
	const oopsyntaxrecognizer::OopModel& oopModel)
{
	for (auto* property : properties)
	{
		classDiagramTemplate->property_name_->Set(property->GetName());
		classDiagramTemplate->property_type_->Set(property->GetType()->GetTypeName());
		classDiagramTemplate->property_->ExpandVariableField();

		if (property->GetType()->GetCategory() != oopsyntaxrecognizer::TypeCategory::standard &&
			property->GetType()->GetCategory() != oopsyntaxrecognizer::TypeCategory::unknown)
		{
			classDiagramTemplate->type_name_rhs_->Set(property->GetType()->GetTypeName());
			classDiagramTemplate->association_relation_->ExpandVariableField();
		}
	}
}

void deamer::external::cpp::tool::ooptoplantuml::ConvertOopModelToPUML::ImplementEnumeration(
	std::unique_ptr<ClassDiagramTemplate>& classDiagramTemplate,
	oopsyntaxrecognizer::EnumObject* type)
{
	classDiagramTemplate->type_name_->Set(type->GetTypeName());

	for (auto member : type->GetMembers())
	{
		classDiagramTemplate->enum_name_->Set(member);
		classDiagramTemplate->enum_member_->ExpandVariableField();
	}

	classDiagramTemplate->enumeration_declaration_->ExpandVariableField();
}
