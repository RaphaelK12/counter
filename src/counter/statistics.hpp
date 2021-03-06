#ifndef counter_statistics_
#define counter_statistics_


namespace counter
 {

   class statistics
    {
     public:

       typedef  std::uint32_t       key_type;
       typedef  std::uint64_t   counter_type;

       typedef  ::counter::statistics statistics_type;

       typedef std::vector< counter_type > container_type;

       statistics()
        {
         m_container.resize(  ::counter::constant::_last, 0 );
        }

       ~statistics(){}

       counter_type operator[]( key_type const& key )const
        {
         return this->m_container[ key ];
        }

       void set( key_type const& key, counter_type const& counter )
        {
         this->m_container[ key ] = counter;
        }

       counter_type const& get( key_type const& key )const
        {
         return m_container[ key ];
        }

       void increase( key_type const& key )
        {
         this->set( key , get( key ) + 1 );
        }

       void reset()
        {
         for( auto & i : m_container )
          {
           i = 0;
          }
        }

       container_type const& container()const{ return m_container; }
       container_type      & container(){ return m_container; }

     private:
       //bool m_ignore;
       container_type m_container;
    };
 }

#endif
