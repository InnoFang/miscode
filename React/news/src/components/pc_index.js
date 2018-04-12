/**
 * Created by InnF on 2018/4/12.
 */

import React from 'react'
import PCHeader from './pc_header'
import PCFooter from './pc_footer'

export default class PCIndex extends React.Component {
    render() {
        return (
            <div>
                <PCHeader/>
                <PCFooter/>
            </div>
        )
    }
}