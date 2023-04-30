#ifndef DEAMER_EXTERNAL_CPP_TOOL_OOPTOPLANTUML_TYPE_CONVERTOOPMODELTOPUML_H
#define DEAMER_EXTERNAL_CPP_TOOL_OOPTOPLANTUML_TYPE_CONVERTOOPMODELTOPUML_H

#include "Deamer/External/Cpp/Tool/OopSyntaxRecognizer/Type/EnumObject.h"
#include "Deamer/External/Cpp/Tool/OopSyntaxRecognizer/Type/OopModel.h"
#include "Deamer/External/Cpp/Tool/OopToPlantUML/Template/ClassDiagram/ClassDiagramTemplate.h"
#include <memory>
#include <string>

namespace deamer::external::cpp::tool::ooptoplantuml
{
	struct ConvertOopModelToPUML
	{
		static std::string ConvertOopModel(const oopsyntaxrecognizer::OopModel& oopModel);

	private:
		static void ImplementFunctions(
			std::unique_ptr<deamer::external::cpp::tool::ooptoplantuml::ClassDiagramTemplate>&
				classDiagramTemplate,
			std::vector<deamer::external::cpp::tool::oopsyntaxrecognizer::FunctionObject*>
				functions,
			const oopsyntaxrecognizer::OopModel& oopModel);
		static void
		ImplementProperties(const std::unique_ptr<ClassDiagramTemplate>& classDiagramTemplate,
							const std::vector<oopsyntaxrecognizer::PropertyObject*>& properties,
							const oopsyntaxrecognizer::OopModel& oopModel);
		static void
		ImplementEnumeration(std::unique_ptr<ClassDiagramTemplate>& classDiagramTemplate,
							 oopsyntaxrecognizer::EnumObject* type);
	};
}

#endif // DEAMER_EXTERNAL_CPP_TOOL_OOPTOPLANTUML_TYPE_CONVERTOOPMODELTOPUML_H
