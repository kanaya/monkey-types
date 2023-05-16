#include <iostream>
#include <random>
#include <vector>

const int len_sentence = 28;
const int n_characters = 27;

class sentence {
	private:
		int s;
		int n;
	public:
		sentence() {
			s = 0;
			n = 0;
		}

		void mutation() {
			std::random_device seed_gen;
			std::default_random_engine engine(seed_gen());
			std::uniform_real_distribution<double> dist(0.0, n_characters);
			for (int i = 0; i < len_sentence; ++i) {
				double r = dist(engine);
				if (r < 1.0) {
					s ^= (0x01 << i);
				}
			}
		}

		void evaluation() {
			n = 0;
			for (int i = 0; i < len_sentence; ++i) {
				int mask = 0x01 << i;
				if (mask bitand s) {
					++n;
				}
			}
		}

		int get_n() const {
			return n;
		}
};