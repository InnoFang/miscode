/**
 * Created by InnF on 2018/4/12.
 */

import React from 'react'
import MobileHeader from './mobile_header'
import MobileFooter from './mobile_footer'
export default class MobileIndex extends React.Component {
    render() {
        return (
            <div id="mobileindex">
                <MobileHeader/>
                <MobileFooter/>
            </div>
        )
    }
}