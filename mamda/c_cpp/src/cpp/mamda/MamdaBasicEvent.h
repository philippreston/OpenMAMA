/* $Id$
 *
 * OpenMAMA: The open middleware agnostic messaging API
 * Copyright (C) 2011 NYSE Technologies, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301 USA
 */

#ifndef MamdaBasicEventH
#define MamdaBasicEventH

#include <mamda/MamdaConfig.h>
#include <mamda/MamdaFieldState.h>
#include <mama/mamacpp.h>

namespace Wombat
{

    /**
     * MamdaBasicEvent is a superclass interface that provides access to
     * common event related fields.  Events types include trades, quotes,
     * order book updates, closing summaries, etc.  See the individual
     * subclasses for specific information about each event type.
     * 
     * Note: Different types of time stamps are available representing the
     * time that the event (trade ,quote,etc) actually occurred, the time
     * the data source/exchange reported it, and the time the NYSE Technologies 
     * feed handler applied an action to the given data item (record, order
     * book, etc.).  Many feeds to not provide a distinction between the
     * event time and the source time (they may be the same) and the
     * granularity of time stamps also varies between data sources.
     */
    class MAMDAExpDLL MamdaBasicEvent
    {
    public:

        /**
         * Get the instruments string symbol.
         *
         * @return Symbol.  This is the "well-known" symbol for the
         * security, including any symbology mapping performed by the
         * publisher.
         */
        virtual const char*  getSymbol() const = 0;
        
        /**
         * Get the string symbol field state 
         *
         * @return MamdaFieldState.  An enumeration representing field state.
         */
        virtual MamdaFieldState  getSymbolFieldState() const = 0;    

        /**
         * Get the participant identifier.
         *
         * @return Participant ID.  This may be an exchange identifier, a
         * market maker ID, etc., or NULL (if this is not related to any
         * specific participant).
         */
        virtual const char*  getPartId() const = 0;
        
        /**
         * Get the participant identifier field state.
         *
         * @return MamdaFieldState.  An enumeration representing field state.
         */
        virtual MamdaFieldState  getPartIdFieldState() const = 0;

        /**
         * Get the event sequence number.
         *
         * @return Source sequence number.  The exchange generated
         * sequence number.
         */
        virtual mama_seqnum_t  getEventSeqNum() const = 0;
        
        /**
         * Get the event sequence number field state.
         * @return MamdaFieldState.  An enumeration representing field state.
         */
        virtual MamdaFieldState  getEventSeqNumFieldState() const = 0;

        /**
         * Get the event time.
         *
         * @return Event time.  Typically, when the event actually
         * occurred.  This is often the same as the "source time", because
         * many feeds do not distinguish between the actual event time and
         * when the exchange sent the message.
         */
        virtual const MamaDateTime&  getEventTime() const = 0;
        
        /**
         * Get the event time field state.
         *
         * @return MamdaFieldState.  An enumeration representing field state.
         */
        virtual MamdaFieldState  getEventTimeFieldState() const = 0;

        /**
         * Get the source time.
         *
         * @return Source time.  Typically, the exchange generated feed
         * time stamp.  This is often the same as the "event time",
         * because many feeds do not distinguish between the actual event
         * time and when the exchange sent the message.
         */
        virtual const MamaDateTime&  getSrcTime() const = 0;
        
        /**
         * Get the source time field state
         *
         * @return MamdaFieldState.  An enumeration representing field state.
         */
        virtual MamdaFieldState  getSrcTimeFieldState() const = 0;

        /**
         * Get the activity time.
         *
         * @return Activity time.  A feed handler generated time stamp
         * representing when the data item was last updated.
         */
        virtual const MamaDateTime&  getActivityTime() const = 0;
        
        /**
         * Get the activity time field state 
         *
         * @return MamdaFieldState.  An enumeration representing field state.
         */
        virtual MamdaFieldState  getActivityTimeFieldState() const = 0;

        /**
         * Get the line time.
         *
         * @return Line time.  A feed handler (or similar publisher) time
         * stamp representing the time that such publisher received the
         * update message pertaining to the event.  If clocks are properly
         * synchronized and the source time (see above) is accurate
         * enough, then the difference between the source time and line
         * time is the latency between the data source and the feed
         * handler.
         */
        virtual const MamaDateTime&  getLineTime() const = 0;
        
        /**
         * Get the line time of the update.
         *
         * @return MamdaFieldState.  An enumeration representing field state.
         */
        virtual MamdaFieldState  getLineTimeFieldState() const = 0;

        /**
         * Get the send time.
         *
         * @return Send time.  A feed handler (or similar publisher) time
         * stamp representing the time that such publisher sent the
         * current message.  The difference between the line time and send
         * time is the latency within the feed handler itself.  Also, if
         * clocks are properly synchronized then the difference between
         * the send time and current time is the latency within the market
         * data distribution framework (i.e. MAMA and the underlying
         * middleware).  See MAMA API: MamaDateTime::currentTime()).
         */
        virtual const MamaDateTime&  getSendTime() const = 0;
        
        /**
         * Get the send time field state 
         *
         * @return MamdaFieldState.  An enumeration representing field state.
         */
        virtual MamdaFieldState  getSendTimeFieldState() const = 0;
        
        /**
         * Get the message qualifier.
         *
         * @return Message Qualifier. The message qualifier provides information
         * in relation to messages duplicate, delayed or out-of-sequence status.
         */
        virtual const MamaMsgQual& getMsgQual() const = 0;

        /**
         * Get the message qualifier field state.
         *
         * @return Message Qualifier. The message qualifier provides information
         * in relation to messages duplicate, delayed or out-of-sequence status.
         */
        virtual MamdaFieldState getMsgQualFieldState() const = 0;

        /**
         * Destructor.
         */
        virtual ~MamdaBasicEvent () {};
    };

} // namespace

#endif // MamdaBasicEventH
