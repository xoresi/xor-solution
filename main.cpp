#include <vector>
#include <iostream>

int main( ) {
	//	relevant IDA pseudo code
	/*
	.text:10081F26                 mov     dword ptr [ebp-36], 3857376241
	.text:10081F2D                 mov     ecx, 12
	.text:10081F32                 mov     dword ptr [ebp-32], 2799954921
	.text:10081F39                 mov     dword ptr [ebp-28], 2257384867
	.text:10081F40
	.text:10081F40 loc_10081F40:                           ; CODE XREF: DllMain(x,x,x)+88↓j
	.text:10081F40                 xor     byte ptr [ebp+ecx-37], 134
	.text:10081F45                 dec     ecx
	.text:10081F46                 test    ecx, ecx
	.text:10081F48                 jnz     short loc_10081F40
	*/

	// let's set up some constants
	constexpr size_t	key { 134 };
	constexpr size_t	str { 3 };

	// alright, we have the "raw" integer values
	constexpr int		val [ str ] {
		3857376241,
		2799954921,
		2257384867
	};

	// honestly i just love vectors
	std::vector < signed char > m_characters { };

	// iterate
	for ( size_t n { }; n < str; n++ ) {
		auto			current = val [ n ];
		auto			*ptr = &current;
 	
		for ( size_t i { }; i < 4; i++ ) {
			m_characters.push_back( *( signed char * ) ( ( uintptr_t ) ptr + i ) );
		}
	}

	for ( auto &c : m_characters ) {
		c ^= key;
		std::cout << c;
	}

	std::cout << std::endl;
}
