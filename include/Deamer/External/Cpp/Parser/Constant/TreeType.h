#ifndef DEAMER_EXTERNAL_PARSER_CONSTANT_TREETYPE_H
#define DEAMER_EXTERNAL_PARSER_CONSTANT_TREETYPE_H

namespace deamer::external::cpp::parser
{
	/*!	\enum TreeType
	 *
	 *	\brief Specifies which tree is used.
	 *
	 *	\details One can modify parser output by specifying what tree is desired.
	 */
	enum class TreeType
	{
		ast,
		cst,
	};
}

#endif // DEAMER_EXTERNAL_PARSER_CONSTANT_TREETYPE_H