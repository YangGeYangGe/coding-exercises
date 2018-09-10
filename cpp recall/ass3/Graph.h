#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

#ifndef ASS3_GRAPH_H
#define ASS3_GRAPH_H
namespace gdwg{
	template <typename N, typename E> class Graph{
	public:
		//constructor
		Graph(){};
		//copy constructors
		Graph(const Graph& g);
		//move constructor
		Graph(Graph&& g);
		//copy assignment
		Graph& operator=(const Graph &g);
		//move assignment
		Graph& operator=(Graph &&g);
		//bool addNode
		bool addNode(const N &node);


		//bool addEdge
		bool addEdge(const N &src, const N &dst, const E &w);

		//bool replace??
		bool replace(const N& oldData, const N& newData);

		// mergeReplace??
		void mergeReplace(const N& oldData, const N& newData);

		//deleteNode
		void deleteNode(const N&) noexcept;
		//delete edge
		void deleteEdge(const N& src, const N& dst, const E& w) noexcept;

		//clear all data
		void clear() noexcept;

		//check if is node
		bool isNode(const N& val) const;

		//check if is connected
		bool isConnected(const N& src, const N& dst) const;

		//print nodes
		void printNodes() const;
		//print edges
		void printEdges(const N& val) const;

		//other operations
		void begin() const{
			iterator = 0;
		};
		bool end() const{
			return (iterator == ns.size());
		};
		void next() const{
			iterator += 1;
		};
		const N& value() const{
			return (ns[iterator]->getdata());
		};



	private:


		class Node{
		public:
			Node(N n) : data(n) {};

			N& getdata() {return data;};
			N& getdata() const {return data;};

			int& getindegree() {return indegree;};
			int& getindegree() const {return indegree;};

			int& getoutdegree() {return outdegree;};
			int& getoutdegree() const {return outdegree;};

			bool operator==(const N &n_data) {

				if((*this).data == n_data){

					return true;
				}

				return false;
			};
			bool operator==(const Node &n_data){
				if(data == n_data.data){
					return true;
				}
				return false;
			}

			Node& operator=(const Node& n){
				data = n.data;
				indegree = n.indegree;
				outdegree = n.outdegree;
				return *this;
			}



		private:
			N data;
			int indegree = 0;
			int outdegree = 0;

		};
		class Edge{
		public:
			Edge(Node &src, Node &dst, const E &we) : s(src), d(dst), w(we) {};
			Node& gets(){return s;}
			Node& gets() const {return s;};

			Node& getd(){return d;};
			Node& getd() const {return d;};

			E& getw(){return w;};
			E& getw() const {return w;};


		private:
			Node& s;
			Node& d;
			E w;

		};

		std::vector<std::shared_ptr<Node>> ns;
		std::vector<std::shared_ptr<Edge>> es;
		mutable unsigned int iterator;

	};

	//#include "Graph.tem"
	//#include "Graph.tem"
	template <typename N, typename E>
	Graph<N,E>::Graph(const Graph& g){

		for(unsigned int index = 0; index < g.ns.size(); ++index){
			ns.push_back(std::shared_ptr<Node>(new Node(*(g.ns[index]))));

		}

		for(unsigned int index = 0; index < g.es.size(); ++index){
			es.push_back(std::shared_ptr<Edge>(new Edge(*(g.es[index]))));
		}
		iterator = g.iterator;

	};
	template <typename N, typename E>
	Graph<N,E>::Graph(Graph &&g) {
		ns = std::move(g.ns);
		es = std::move(g.es);
		iterator = std::move(g.iterator);
	};
	//copy assignment
	template <typename N, typename E>
	Graph<N,E>& Graph<N,E>::operator=(const Graph &g) {
		if(this != &g){

			ns.clear();
			es.clear();

			for(unsigned int index = 0; index < g.ns.size(); ++index){

				ns.push_back(std::shared_ptr<Node>(new Node(*(g.ns[index]))));

			}
			for(unsigned int index = 0; index < g.es.size(); ++index){
				es.push_back(std::shared_ptr<Edge>(new Edge(*(g.es[index]))));

			}
			iterator = g.iterator;
		}
		return *this;
	};
	//move assignment
	template <typename N, typename E>
	Graph<N,E>& Graph<N,E>::operator=(Graph &&g) {
		if(this != &g){

			ns.clear();
			es.clear();

			ns = std::move(g.ns);
			es = std::move(g.es);
			iterator = std::move(g.iterator);
		}
		return *this;
	};

	//addnode

	template <typename N, typename E>
	bool Graph<N,E>::addNode(const N &node) {

		for(unsigned int index = 0; index < ns.size(); ++index){
			if((*ns[index]) == node){
				return false;
			}
		}

		Node a{node};
		std::shared_ptr<Node> n = std::make_shared<Node>(a);
		ns.push_back(std::move(n));
		return true;
	};


	template <typename N, typename E>
	bool Graph<N,E>::addEdge(const N &src, const N &dst, const E &w) {
		int in_index = 0;
		int out_index = 0;
		try {
			int count = 0;
			for (begin(); !end(); next()){
				if(value() == src){
					out_index = iterator;
					count++;
				}
				if(value() == dst){
					in_index = iterator;
					count++;
				}
			}
			if(count != 2){
				throw false;
			}
		}catch(bool b){
			throw std::runtime_error("a runtime error");

		}
		for(unsigned int index = 0; index < es.size(); ++index){
			if(es[index]->gets() == src && es[index]->getd() == dst && es[index]->getw() == w){
				return false;
			}
		}

		Edge a(*ns[out_index],*ns[in_index],w);
		std::shared_ptr<Edge> e = std::make_shared<Edge>(a);

		es.push_back(std::move(e));

		(ns[in_index]->getindegree())++;
		(ns[out_index]->getoutdegree())++;



		return true;
	}

	template <typename N, typename E>
	bool Graph<N,E>:: replace(const N& oldData, const N& newData){
		try{
			if(!isNode(oldData)){
				throw 1;
			}
		}catch(int a){
			throw std::runtime_error("a runtime error");
		}

		if(isNode(newData)){
			return false;
		}
		for(unsigned int index = 0; index < ns.size(); ++index){
			if(ns[index]->getdata() == oldData){
				ns[index]->getdata() = newData;
			}
		}

		return true;
	}

	template <typename N, typename E>
	void Graph<N,E>::mergeReplace(const N& oldData, const N& newData){
		int newnode = 0;
		try{
			for(unsigned int index = 0; index < ns.size(); ++index){
				int count = 0;
				for (begin(); !end(); next()){
					if(value() == oldData){
						count++;
					}
					if(value() == newData){
						newnode = iterator;
						count++;
					}
				}
				if(count != 2){
					throw false;
				}
			}
		}catch(bool b){
			throw std::runtime_error("a runtime error");
		}

		//        for(int index = 0; index < es.size(); ++index){
		//            if(es[index]->gets().getdata() == oldData){
		//                es[index]->gets() = *ns[newnode];
		//            }
		//            if(es[index]->getd().getdata() == oldData){
		//                es[index]->getd() = *ns[newnode];
		//            }
		//        }
		//        es.erase(std::unique(es.begin(), es.end(),
		//                             [] (const std::shared_ptr<Edge>& a, const std::shared_ptr<Edge>& b){
		//                                return (a->getd() == b->getd() &&
		//                                        a->getw() == b->getw() &&
		//                                        a->gets() == b->gets());
		//                            }
		//             ));
		//        ns.erase(std::unique(ns.begin(), ns.end(),
		//                             [] (const std::shared_ptr<Node>& a, const std::shared_ptr<Node>& b){
		//                                 return (a->getdata() == b->getdata() &&
		//                                         a->getoutdegree() == b->getoutdegree() &&
		//                                         a->getindegree() == b->getindegree());
		//                             }
		//        ));


		for(unsigned int index = 0; index < es.size();++index){
			if(es[index]->gets().getdata() == oldData ){
				Edge e1(*ns[newnode],es[index]->getd(),es[index]->getw());

				std::shared_ptr<Edge> e = std::make_shared<Edge>(e1);
				es.erase(es.begin()+index);
				es.emplace(es.begin()+index, e);
				--index;

			}else if(es[index]->getd().getdata() == oldData ){
				Edge e1(es[index]->gets(),*ns[newnode],es[index]->getw());
				std::shared_ptr<Edge> e = std::make_shared<Edge>(e1);

				es.erase(es.begin()+index);
				es.emplace(es.begin()+index, e);
				--index;

			}

		}
		/*auto last= std::unique(es.begin(), es.end(),
		 [] (const std::shared_ptr<Edge>& a, const std::shared_ptr<Edge>& b){
		 return (a->getd().getdata() == b->getd().getdata() &&
		 a->getw() == b->getw() &&
		 a->gets().getdata() == b->gets().getdata());
		 }
		 );
		 es.erase(last, es.end());
		 */


		for(unsigned int index1 = 0; index1 < es.size(); ++index1){
			for(unsigned index2 = 0; index2 < es.size(); ++index2){
				if(index1 != index2){
					if(es[index1]->getd().getdata() == es[index2]->getd().getdata() &&
					   es[index1]->getw() == es[index2]->getw() &&
					   es[index1]->gets().getdata() == es[index2]->gets().getdata()){

						es.erase(es.begin()+index2);
						--index2;
					}
				}
			}
		}
		ns.erase(std::find_if(ns.begin(), ns.end(),
							  [oldData] (const std::shared_ptr<Node>& a){
								  return (a->getdata() == oldData);
							  }
							  ));

	};


	template<typename N, typename E>
	void Graph<N,E>::deleteNode(const N & n) noexcept {
		if(isNode(n)){
			auto tempi = es.begin();
			while(tempi != es.end()){
				tempi = std::find_if(es.begin(), es.end(),
									 [n](const std::shared_ptr<Edge>& a){
										 if(a->getd().getdata() == n){
											 a->gets().getoutdegree()--;
											 return true;

										 }else if (a->gets().getdata() == n){
											 a->getd().getindegree()--;
											 return true;
										 }else{
											 return false;
										 }
									 }
									 );
				es.erase(tempi);
			}


			ns.erase(std::find_if(ns.begin(),ns.end(),
								  [n](const std::shared_ptr<Node>& b){
									  return (b->getdata() == n);
								  }

								  ));


		}
	}

	template <typename N, typename E>
	void Graph<N,E>::deleteEdge(const N& src, const N& dst, const E& w) noexcept{
		if(isConnected(src, dst)){
			es.erase(std::find_if(es.begin(), es.end(),
								  [src,dst,w](const std::shared_ptr<Edge>& a){

									  if(a->gets() == src&&
										 a->getd() == dst &&
										 a->getw() == w){

										  a->gets().getoutdegree()--;
										  a->getd().getindegree()--;
										  return true;
									  } else {
									  	return false;
									  }

								  }));
		}
	}

	template <typename N, typename E>
	void Graph<N,E>::clear() noexcept {
		ns.clear();
		es.clear();
		iterator = 0;
	}


	template <typename N, typename E>
	bool Graph<N,E>::isNode(const N& val) const{
		for(unsigned int index = 0; index < ns.size(); ++index){
			if((*ns[index] == val)){
				return true;
			}
		}
		return false;


	};

	//check if is connected
	template <typename N, typename E>
	bool Graph<N,E>::isConnected(const N& src, const N& dst) const{
		try {
			int count = 0;
			for (begin(); !end(); next()){
				if(value() == src){
					count++;
				}else if(value() == dst){
					count++;
				}
			}
			if(count != 2){
				throw false;
			}
		}catch(bool b){
			throw std::runtime_error("a runtime error");
		}

		for(unsigned int index = 0; index < es.size(); ++index){
			if(es[index]->gets() == src && es[index]->getd() == dst){
				return true;
			}
		}

		return false;
	};

	template <typename N, typename E>
	void Graph<N,E>::printNodes() const {
		Graph<N,E> temp = *this;
		auto lambda =[](const std::shared_ptr<Node>& a,const std::shared_ptr<Node>& b){
			if(a->getoutdegree() != b->getoutdegree()){

				return (a->getoutdegree() < b->getoutdegree());
			} else{
				return a->getdata() < b->getdata();
			}
		};
		std::sort( temp.ns.begin(), temp.ns.end(), lambda);
		for(temp.begin(); !temp.end(); temp.next()){
			std::cout<< temp.value()<<"\n";
		}
	}

	template <typename N, typename E>
	void Graph<N,E>::printEdges(const N &val) const {

		try {
			int count = 0;
			for (begin(); !end(); next()){
				if(value() == val){
					count++;
					break;
				}
			}
			if(count != 1){
				throw false;
			}
		}catch(bool b){

			throw std::runtime_error("a runtime error");

		}
		std::cout << "Edges attached to Node "<<val<<"\n";
		std::vector<std::shared_ptr<Edge>> temp;
		for(unsigned int index = 0; index < es.size(); ++index){
			if(es[index]->gets() == val){
				temp.push_back(es[index]);
			}
		}
		if(temp.size() == 0){
			std::cout << "(null)\n";
		} else{
			auto lambda =[](const std::shared_ptr<Edge>& a,const std::shared_ptr<Edge>& b){
				if(a->getw() != b->getw()){
					return (a->getw() < b->getw());
				} else{
					return (a->getd().getdata() < b->getd().getdata());
				}
			};
			std::sort( temp.begin(), temp.end(), lambda);
			for(auto i : temp){
				std::cout<< i->getd().getdata() <<" "<<i->getw()<<"\n";
			}

		}
	};



}
#endif //ASS3_GRAPH_H
